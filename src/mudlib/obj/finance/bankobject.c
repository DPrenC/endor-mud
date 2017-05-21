/**
 * SIMAURIA '/obj/finance/bankobject.c'
 */

inherit NMB;

#include <wizlevels.h>
#include <config.h>
#include <money.h>
#include "/secure/userinfo.h"

#define BANK_CHECK 20 // bank-accounts to check during 1 reset

private mixed *account;
// ({name,amount,created,last_deposit,last_withdraw,bank})

public string curr_account; // the current player to check
                            // if the account might be deleted

public mixed *QueryAccount(mixed character, string bank)
{
    mixed *result;
    if (!character ||(!stringp(character) && !intp(character))) return 0;
    if (stringp(character))
    {
        DBMASTER->Exec("select id, CharacterID, amount, created, deposit, withdraw, bank "
                       "from accounts where bank='" + db_conv_string(bank) + "' and CharacterID=(select id "
                       "from characters where name='" + db_conv_string(LOWER(character)) + "')");
    }
    else
    {
        DBMASTER->Exec("select id, CharacterID, amount, created, deposit, withdraw, bank "
                       "from accounts where bank='" + db_conv_string(bank) + "' and CharacterID=" + character);
    }
    result = (mixed)DBMASTER->Fetch();
    if (!result) return 0;
    result[A_CHARACTER] = to_int(result[A_CHARACTER]);
    result[A_ACCOUNT_ID] = to_int(result[A_ACCOUNT_ID]);
    result[A_AMOUNT] = to_int(result[A_AMOUNT]);
    result[A_CREATED] = to_int(result[A_CREATED]);
    result[A_DEPOSIT] = to_int(result[A_DEPOSIT]);
    result[A_WITHDRAW] = to_int(result[A_WITHDRAW]);
    result[A_BANK] = to_string(result[A_BANK]);
    return result;
}

public varargs mixed QueryAccounts(mixed character, int order)
// devuelve un alists ({({bancos}),({cantidades})}),
// ordenadas por <order>. order puede ser: F_ORDER_AMOUNT (por defecto), F_ORDER_NAME, o F_ORDER_DATE
{
    mixed *result;
    mixed chaccounts = ({({}), ({})});
    string orderby;

    if (!character ||(!stringp(character) && !intp(character))) return 0;
    switch (order)
    {
        case F_ORDER_AMOUNT: default: orderby = "amount"; break;
        case F_ORDER_NAME: orderby = "bank"; break;
        case F_ORDER_DATE: orderby = "created"; break;
    }
    if (stringp(character))
    {
        DBMASTER->Exec("select bank, amount  from accounts where CharacterID=("
                       "select id from characters where name='" + db_conv_string(LOWER(character)) + "') "
                       "order by " + orderby);
    }
    else
    {
        DBMASTER->Exec("select bank, amount  from accounts where CharacterID=" + character +
                       " order by " + orderby);
    }
    while (result = (mixed)DBMASTER->Fetch())
    {
        chaccounts[0] += ({to_string(result[0])});
        chaccounts[1] += ({to_int(result[1])});
    }
    return chaccounts;
}


public void create() {
    seteuid(getuid());
    if (clonep(TO))
    {
        destruct(TO);
        return;
    }
}

private void log_action(string what)
{
    string po,tp,ti;
    if (TP) tp = capitalize(getuid(TP));
    else tp = "(none)";
    if (TI) ti = capitalize(getuid(TI));
    else ti = "(none)";
    if (PO) po = object_name(PO);
    else po = "(none)";
    log_file(BANKLOG,"\n"+ctime()+" "+what+"\n [TP: "+tp+", TI: "+ti+
             ", PO: "+po+"]\n");
}

public int HasAccount(mixed player, string bank)
{
    mixed *result;
    if (!player || (!stringp(player) && !intp(player))) return 0;
    if (intp(player))
    {
        DBMASTER->Exec("select count(id) from accounts where CharacterID=" + player + " and bank='" + db_conv_string(LOWER(bank)) + "'");
    }
    else
    {
        DBMASTER->Exec("select count(id) from accounts "
                       "where bank='" + db_conv_string(LOWER(bank)) + "' and CharacterID=(select ID from "
                       "characters where name='" + db_conv_string(LOWER(player)) + "')");
    }
    result = DBMASTER->Fetch();
    return to_int(result[0]) > 0;
}


public int SetAccount(mixed player, string bank, int amount)
{
    int dif, sincuenta;
    mixed *placcount, *uinfo;

    if (   amount<0 || !bank || !player || (!intp(player) && !stringp(player))
        || !(uinfo = MASTER->find_userinfo(player)))
    {
        return 0;
    }

    if (!(placcount = QueryAccount(player, bank)))
    {
        sincuenta = 1;
        placcount = allocate(A_COUNT);
        placcount[A_CHARACTER] = uinfo[USER_ID];
        placcount[A_CREATED] = time();
        placcount[A_BANK] = bank;
        log_action("cuenta de "+capitalize(uinfo[USER_NAME])+" creada ("+
                   to_string(amount)+" U.M.S.)");
    }
    else if (dif = amount-to_int(placcount[A_AMOUNT]))
    {
        if (  (TP&&getuid(TP)!=uinfo[USER_NAME])
            ||(TI&&getuid(TI)!=uinfo[USER_NAME])
            ||TP!=TI)
          log_action("balance de "+capitalize(uinfo[USER_NAME])+" cambiado ("+
                     to_string(placcount[A_AMOUNT])+
                     ((sign(dif)==-1)?" - ":" + ")+
                     to_string(abs(dif))+" = " +
                     to_string(amount)+" U.M.S.)");
    }
    placcount[A_AMOUNT] = amount;
    placcount[dif>0?A_DEPOSIT:A_WITHDRAW] = time();
    if (sincuenta)
    {
        DBMASTER->Exec("insert into accounts values(default, " + placcount[A_CHARACTER] + ", " +
                       placcount[A_AMOUNT] + ", " + placcount[A_CREATED] +
                       ", " + placcount[A_DEPOSIT] + ", " + placcount[A_WITHDRAW] +
                       ", '" + placcount[A_BANK] + "')");
    }
    else
    {
        DBMASTER->Exec("update accounts set "
                       "amount=" + amount + ", "
                       "deposit=" + placcount[A_DEPOSIT] + ", "
                       "withdraw=" + placcount[A_WITHDRAW] + " where CharacterID=" +
                       uinfo[USER_ID] + " and bank='" + db_conv_string(LOWER(bank)) + "'");
    }
    return 1;
}


public int AddAccount(mixed player, string bank, int amount)
{
    mixed *uinfo, *placcount;
    if (   !player || (!stringp(player) && !intp(player)) || !bank
        || !(uinfo = MASTER->find_userinfo(player)))
    {
        return 0;
    }
    if (!(placcount = QueryAccount(player, bank)))
    {
        return SetAccount(player, bank, amount);
    }
    else
    {
        if (amount > 0 && __INT_MAX__ - placcount[A_AMOUNT] - amount < 0)
        // no puede ingresar todo ese dinero, porque daría overflow.
        {
            CHANNELMASTER->SendEmote("error", sprintf("ha intentado ingresar %d U.M.S "
                                     "(%s) en el banco, provocándose un overflow al "
                                     "sumar esta cantidad con su saldo actual, que "
                                     "es de %d U.M.S (%s)", amount,
                                     MONEY_LIB->Value2String(amount),
                                     placcount[A_AMOUNT],
                                     MONEY_LIB->Value2String(placcount[A_AMOUNT])));

            // hacemos un log del error para ir controlando... Si a un player le pasa
            // esto, nada bueno puede haber hecho ;)
            log_file(MONEY_OVERFLOW, sprintf("%-78=s", ctime() + ": " + CAP(uinfo[USER_NAME]) +
                                       " intentó ingresar " + amount + " U.M.S, "
                                       "con un saldo de " +
                                       placcount[A_AMOUNT] + " UMS.\n\n"));
            return 0;
        }
    }
    return SetAccount(player,bank, placcount[A_AMOUNT]+amount);
}

public int CloseAccount(string player, string bank)
{
    mixed *uinfo, *placcount;
    int amount;
    if (   !bank || !player || (!intp(player) && !stringp(player))
        || !(uinfo = MASTER->find_userinfo(player)))
    {
        return -1;
    }
    if (!(placcount = QueryAccount(player, bank))) return -1;
    amount = placcount[A_AMOUNT];
    DBMASTER->Exec("delete from accounts where CharacterID=" + uinfo[USER_ID] + " and bank='" + db_conv_string(LOWER(bank)) + "'");
    if (!DBMASTER->AffectedRows())
    {
        return raise_error("Error al eliminar la cuenta de " + CAP(uinfo[USER_NAME]) + ".\n"), 0;
    }
    log_action("cuenta de "+capitalize(uinfo[USER_NAME])+" cerrada ("+
               to_string(amount)+" U.M.S.)");
    return amount;
}

public int CloseAccounts(mixed player)
{
    int res;
    mixed *uinfo;
    if (!player || (!intp(player) && !stringp(player))) return 0;
    if (!(uinfo = MASTER->find_userinfo(player))) return -1;
    DBMASTER->Exec("delete from accounts where CharacterID=" + uinfo[USER_ID]);
    res = DBMASTER->AffectedRows();
    if (res) log_action("Cuenta de " + CAP(uinfo[USER_NAME]) + " cerradas: " + res);
    return res;
}



public varargs mixed *Top(string bank, int number, int order)
// devuelve un alist ({({nombres}), ({cantidades})})
// Se ordenará según order, que puede ser: F_ORDER_AMOUNT, F_ORDER_NAME,
// o F_ORDER_DATE. si no se selecciona banco y se pone order F_ORDER_AMOUNT, se ordenará por el
// total de amount cada personaje
{
    mixed res = ({({}), ({})});
    string orderby;

    mixed *acc;
    if (!number) number = 10;
    switch (order)
    {
        case F_ORDER_AMOUNT: default: orderby = "amount"; break;
        case F_ORDER_NAME: orderby = "bank"; break;
        case F_ORDER_DATE: orderby = "created"; break;
    }
    
    if (bank)
    {
        DBMASTER->Exec("select ch.name as nombre, ac.amount as saldo from accounts ac "
                       "inner join characters ch on ac.CharacterID = ch.id " +
                       " where bank='" + db_conv_string(LOWER(bank)) + "' order by ac." + orderby + " desc limit " + number);
    }
    else if (order == F_ORDER_AMOUNT)
    {
        DBMASTER->Exec("select ch.name, sum(ac.amount) as total from accounts ac inner join "
                       "characters ch on ac.CharacterID = ch.id where amount > 0 group by ch.name order by total desc limit " + number);
    }
    else
    {
        DBMASTER->Exec("select ch.name as nombre, ac.amount as saldo from accounts ac "
                       "inner join characters ch on ac.CharacterID = ch.id " +
                       " order by ac." + orderby + " desc limit " + number);
    }
    while (acc = DBMASTER->Fetch())
    {
        res[0] += ({to_string(acc[0])});
        res[1] += ({to_int(acc[1])});
    }
    return res;
}

public int QueryTotalAmount(mixed player)
// Devuelve el total de dinero de un determinado jugador
{
    mixed *res;
    if (!player || (!intp(player) && !stringp(player))) return 0;
    if (intp(player))
    {
        DBMASTER->Exec("select sum(amount) from accounts where CharacterID=" + player);
    }
    else
    {
        DBMASTER->Exec("select sum(amount) from accounts where CharacterID=(select id "
                       "from characters where name='" + player + "')");
    }
    res = DBMASTER->Fetch();
    return to_int(res[0]);
}





public void reset()
{
    // eliminamos las cuentas de los wizards o de los personajes que ya no existen
    DBMASTER->Exec("delete from accounts where CharacterID in(select id from characters where level > 0) or CharacterID not in (select id from characters)");
}

public int RegisterBank(string bank, string path, int *close_time)
{
    mixed res;
    if (!bank) return 0;
    DBMASTER->Exec("select count(id) from banks where name='" + bank + "'");
    res = DBMASTER->Fetch();
    if (!res || !to_int(res[0]))
    {
        DBMASTER->Exec("insert into banks values (default, '" + bank + "', '"+ path + "', " +
            (close_time && sizeof(close_time) ? "'" + implode(map(close_time, SF(to_string)), ",") + "'" : "null") + ")");
    }
    else
    {
        DBMASTER->Exec("update banks set name='" + bank + "', path='" + path + "', CloseTime=" +
            (close_time && sizeof(close_time) ? "'" + implode(map(close_time, SF(to_string)), ",") + "' " : "null ") + "where name='" + bank + "'");
    }
    return 1;
}


public mixed *QueryBankInfo(mixed bank)
{
    mixed res;
    int *close;
    if (!bank || (!intp(bank) && !stringp(bank))) return 0;
    DBMASTER->Exec("select id, name, path, CloseTime from banks where " +
                   (stringp(bank) ? "name='" + bank + "'" : "id=" + bank));
    res = DBMASTER->Fetch();
    if (!res) return 0;
    res[BANK_ID] = to_int(res[BANK_ID]);
    res[BANK_NAME] = to_string(res[BANK_NAME]);
    res[BANK_PATH] = to_string(res[BANK_PATH]);
    res[BANK_CLOSE] = map(explode(to_string(res[BANK_CLOSE]), ","), SF(to_int));
    return res;
}

