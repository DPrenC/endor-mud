/**
 * /std/banco.c
 */

#include <rooms.h>
#include <keeper.h>
#include <money.h>
#include <moving.h>
#include <wizlevels.h>
#include <properties.h>
#include <nightday.h>
#include <sounds.h>
#include <scheduler.h>
#include <input_to.h>

#define DICE(s) (KeeperName(K_CAP) + " dice: " + s)
#define JOIN_PRICE      5
#define UID(x)          getuid(x)
#define FOLLETOS        20 // número de folletos que contiene la caja



inherit SCHEDULER_ROOM;
inherit KEEPER;

private int pLeaflets; // si hay o no hay folletos en el banco
private int num_folletos; // número de folletos que tiene la caja
private float pFee; // porcentaje de comisión que se cobrará al ingresar dinero
private int pFixedFeeTransfer; // cantidad, en cobre, que se cobrará por transferir dinero, y que
// también se considerará la cantidad mínima a sacar. Esto se utiliza como base de tarificación del
// servicio
private float pFeeTransfer; // porcentaje de comisión por transferencia
private string pBankName; // el nombre del banco. Se usará para las distintas cuentas


// SetLeaflets(int i)
// añade o quita la caja con folletos del banco
public int SetLeaflets(int i) { return pLeaflets = i; }

// QueryLeaflets()
// devuelve el valor de pLeaflets, que indica si hay o no hay folletos en este
// banco
public int QueryLeaflets() { return pLeaflets; }


// Comisión que cobrará el banco por ingresar dinero
public float SetFee(float perc) { return pFee = perc; }
public float QueryFee() { return pFee; }

// comisión en cobres, por transferencias
public int SetFixedFeeTransfer(int i) { return pFixedFeeTransfer = i; }
public int QueryFixedFeeTransfer() { return pFixedFeeTransfer; }

public float SetFeeTransfer(float i) { return pFeeTransfer = i; }
public float QueryFeeTransfer() { return pFeeTransfer; }


// Nombre del banco, se utilizará para identificar cada banco con las cuentas de sus clientes
public string SetBankName(string b) {
    if (b) BANKOBJECT->RegisterBank(b, object_name(), QueryCloseTime());
    return pBankName = b;
}
public string QueryBankName() { return pBankName; }


// Cálculo de comisión:
private int CalcFee(int x)
{
    return to_int(x/100*pFee) || 1;
}
public int CalcFeeTransfer(int money)
{
        return (pFixedFeeTransfer + to_int(money / 100 * pFeeTransfer)) || 1;
}


// QueryIntLong(). Se sobrecarga para añadir el detalle de los folletos.
public string QueryIntLong()
{
    if (!pLeaflets) return ::QueryIntLong();
    return ::QueryIntLong() + "Encima del mostrador puedes ver una caja con "
                              "folletos con información sobre el funcionamiento "
                              "de los bancos.\n";
}

private string mirar_caja()
{
    if (!pLeaflets) return 0;

    return "Es una caja con folletos en los que se explica el funcionamiento "
           "del banco. " + (!num_folletos ? "Ahora mismo está vacía.\n" :
                            "Si lo deseas puedes coger uno.\n");
}


public void create()
{
    ::create();
    SetIntShort("un banco");
    SetIntLong("Te encuentras en un banco. "
               "Aquí podrás abrir y cancelar tu cuenta, ver tu saldo actual, o "
               "sacar y meter dinero.\n");
    SetIntBright(45);

    // impedimos que se pueda hacer magia
    ForbidAllMagic();

    // Añadimos el detalle de la caja con folletos
    AddDetail(({"caja","caja de folletos","caja con folletos"}), SF(mirar_caja));

    // la caja tiene 20 folletos... No es plan de que algún player gracioso se
    // ponga a coger folletos y a tirarlos en cualquier lado, y que salgan
    // infinitos folletos
    num_folletos = FOLLETOS;

    // por defecto siempre habrá en el banco una caja con folletos
    SetLeaflets(1);

    // Comisión. Por defecto, 0,5%
    SetFee(2.0);
    // comisión fija por transferencia, 5 mithriles
    SetFixedFeeTransfer(25000);
    // Porcentaje de dinero que se cobrará por transferencia, 15%
    SetFeeTransfer(15.00);

    // horario de cierre
    SetCloseTime(S_CLOSED_AT_NIGHT);
    
    // ponemos las acciones para las funciones del banco
    AddRoomCmd(({"abrir","crear",}),"cmd_create");
    AddRoomCmd(({"ingresar","meter"}),"cmd_deposit");
    AddRoomCmd(({"sacar","extraer"}),"cmd_withdraw");
    AddRoomCmd("cerrar","cmd_close");
    AddRoomCmd("balance","cmd_balance");
    AddRoomCmd("mejores","cmd_list");
    AddRoomCmd("matar","cmd_kick");
    AddRoomCmd("robar","cmd_steal");
    AddRoomCmd("coger","cmd_folleto");
}
private int Named()
{
    if (!pBankName)
    {
        return notify_fail("Este banco no tiene nombre asociado, por lo que no podemos atenderte. "
                           "Por favor, contacta con un wizard.\n");
    }
    return 1;
}


// HasAccount()
// Devuelve 1 si el player con el nombre <name> tiene cuenta en el banco, 0 con
// notify_fail, si no tiene. Toma como referencia a this_player.
private int HasAccount()
{
    if (!Named()) return 0;
    if (BANKOBJECT->HasAccount(UID(TP), pBankName)) return 1;
    return notify_fail(KeeperName(K_CAP) + " te dice: Lo siento, pero no "
                       "tienes cuenta en este banco.\n",
                       NOTIFY_NOT_VALID);
}


// get_date(int tiempo)
// devuelve la fecha producto de la funcion ctime(tiempo) pero convertida al castellano.
private string get_date(int tiempo)
{
    if (!tiempo) return "No hay datos";
    return STR->etime(0, ctime(tiempo));
}

// get__amount(string name)
// dado el nombre de player <name>, devuelve un string con su saldo actual.
private string get_amount(string name)
{
    return MONEY_LIB->Value2String(BANKOBJECT->QueryAccount(name, pBankName)
                                               [A_AMOUNT]);
}

protected string what_am_i(int amount)
{
    amount = amount/1000000;
    if (!amount) return "";
    if (amount > 999999) return DICE("Es billonario");
    if (!IS_JAN(TP)) return DICE("Es millonario");
    return DICE("Tiene "+amount+" millones");
}

protected string format_list(int pos,string player,int amount)
{
    return STR->radjust(to_string(pos+1),2,"0")+". "+
           STR->ladjust(capitalize(player)+" ",13,".")+
           STR->radjust(" "+what_am_i(amount),30,".");
}

protected varargs string *list_top10(int todos)
{
    mixed res;
    int i;
    string *list;

    res = BANKOBJECT->Top(0, 10);

    list = ({"Lista de los mejores clientes de " + (todos ? "la red bancaria de Simauria:\n" : "este banco:\n")});
    for (i=0;i<sizeof(res[0]); i++)
        list+=({format_list(i,res[0][i],res[1][i])});
    return list;
}

public int cmd_list(string str)
{
    if (str != "todos" && str != "este")
    {
        return notify_fail("mejores <todos>: La lista  de los mejores clientes de la red de bancos de todo el mud.\n"
                           "mejores <este>: Mejores clientes de este banco.\n", NOTIFY_NOT_VALID);
    }

    if (!Named()) return 0;
    // si no puede atender al player...
    if (CantAttend(K_NOTIFY)) return 0;

    if (str == "todos") STR->smore(list_top10(1),TP->QueryPageSize());
    else STR->smore(list_top10(),TP->QueryPageSize());
    return 1;
}

public void _transfer_from_limbo(string str)
{
    mixed *account;
    if (!str || member(({"si", "s", "sí", "no", "n"}), (str = LOWER(str))) < 0)
    {
        write("\nDebes pulsar s, o n.\n");
        input_to("_transfer_from_limbo", INPUT_PROMPT,
                 "¿Deseas transferir todo el dinero de la cuenta de limbo a este banco? Pulsa "
                 "s, o n. ");
        return;
    }
    if (str == "n" || str == "no")
    {
        write("\nDe acuerdo, como quieras.\n");
        return;
    }
    account = BANKOBJECT->QueryAccount(TNREAL, "limbo");
    write("Transfiriendo " + MONEY_LIB->Value2String(account[A_AMOUNT]) + " al banco de " + CAP(pBankName) + ".\n");
    if (!BANKOBJECT->AddAccount(TNREAL, pBankName, account[A_AMOUNT]))
    {
        write("Error al transferir. Por favor, contacta con un wizard.\n");
        return;
    }
    BANKOBJECT->CloseAccount(TNREAL, "limbo");
    write("¡Hecho! " + "Tu saldo actual es de " + get_amount(UID(TP)) + ".\n");
}

    
    public int cmd_create(string str)
{
    if (!str || LOWER(str) != "cuenta")
    {
        return notify_fail("¿" +CAP(query_verb()) + " qué?\n", NOTIFY_ILL_ARG);
    }

    // Si el banco no tiene nombre, no cuela
    if (!Named()) return 0;
    
    // si no lo puede atender...
    if (CantAttend(K_NOTIFY)) return 0;
    if (HasAccount())
    {
        return notify_fail(KeeperName(K_CAP) + " te mira, consulta "
                           "unos papeles y te dice: Lo siento " + CAP(TNAME) +
                           ", pero sólo se puede abrir una cuenta por cliente, "
                           "y tú ya tienes una abierta.\n", NOTIFY_NOT_VALID);
    }
    if (!Pay(TP,JOIN_PRICE, "por la apertura de una cuenta"))
    {
        return notify_fail(KeeperName(K_CAP) + " te dice: Lo siento, "
                           "pero para abrir una cuenta necesitarás " +
                           MONEY_LIB->Value2String(JOIN_PRICE) + ".\n",
                           NOTIFY_NOT_VALID);
    }

    // abrimos la cuenta
    BANKOBJECT->SetAccount(UID(TP), pBankName, 0);
    write("¡Ahora eres miembro del banco de " + CAP(pBankName) + "!\n");
    if (pBankName != "limbo" && !IS_BEGINNER(TP) && BANKOBJECT->HasAccount(TNREAL, "limbo"))
    // se le pregunta si quiere transferir el dinero que tiene en limbo a esta cuenta
    {
        write("Hemos observado que tienes una cuenta bancaria en el banco de Limbo. Debido a que ya "
              "no eres un jugador novato, te damos la posibilidad de que transfieras todo el "
              "dinero de la cuenta de Limbo a esta oficina.\n");
        input_to("_transfer_from_limbo", INPUT_PROMPT,
                 "¿Deseas transferir el dinero de limbo a este banco? escribe s, o n. ");
    }
    return 1;
}

public int cmd_close(string str)
{
    int remaining;

    if (!str || LOWER(str) != "cuenta")
    {
        return notify_fail("¿Cerrar qué?");
    }
    if (!Named()) return 0;
    if (CantAttend(K_NOTIFY)) return 0;
    if (!HasAccount()) return 0;

    remaining = BANKOBJECT->CloseAccount(UID(TP), pBankName);
    if (!remaining)
    {
        KeeperEmote(({"mira algo en el libro de registros mientras te dice: De acuerdo. Tu cuenta "
                      "queda cerrada.\n",
                      "le dice algo a " + CAP(TNAME) + " mientras anota algo en su libro de registros.\n"}));
        return 1;
    }
    MONEY_LIB->AdjustMoney(TP,MONEY_DEMON->CreateMoney(remaining,
                                                       MONEY_LIB->QueryValuta()));
    KeeperEmote(({"abre un gran armario de acero, del que extrae una gran "
                  "saca repleta de monedas. A continuación, te da el dinero que "
                  "te quedaba en la cuenta.\n",
                  "abre un gran armario de acero, del que extrae una saca "
                  "repleta de monedas. De ella extrae " +
                  (remaining > 500000 ? "gran cantidad de " : "algo de ") +
                  "dinero que entrega a " + CAP(TNAME) + ".\n"}));

    play_sound(environment(TP), SND_SUCESOS("dinero"));
    KeeperEmote("introduce la saca en el armario, que cierra a continuación.\n");
    return 1;
}

public int cmd_deposit(string str)
{
    mixed moneyob;
    int money_value, i, amount;
    mapping money_map, temp_map;
    string *no_ingresado = ({});
    string money_short, *ids;

    if(!str || str == "?")
    {
        return notify_fail("Uso: ingresar <dinero>. "
                           "<dinero> puede ser cualquier cosa como '10 cobre', "
                           "o '10 cobre y 12 platino', ...",
   			                NOTIFY_ILL_ARG);
    }
    if (!Named()) return 0;
    // si no puede atender al player...
    if (CantAttend(K_NOTIFY)) return 0;
    // si no tiene cuenta...
    if(!HasAccount()) return 0;

    money_map = ([]);
    if (str == "todo" || str == "dinero")
    {
        if (   !(moneyob = MONEY_LIB->QueryMoneyObject(TP))
            || !(amount = moneyob->QueryValue()))
        // no tiene dinero
        {
            return notify_fail("No tienes dinero.\n", NOTIFY_NOT_VALID);
        }
        // asignamos a money_map el valor del mapping del dinero del jugador
        money_map = moneyob->QueryMoney();
        MONEY_LIB->PayMoney(TP,money_map);
    }
    else
    // no ha puesto ingresar todo, así que se calcula cuanto quiere ingresar.
    {
        i = sizeof(ids = explode(implode(explode(str," y "),","),","));
        ids = map(ids, SF(trim));

        while(i--)
        {
            if (!moneyob = search(TP,ids[i],SEARCH_INV|SM_OBJECT|SM_IGNLIGHT))
            { // esta porción de dinero no la tiene en su inventario.
                no_ingresado += ({"No tienes " + ids[i]});
                ids = ids[.. i -1] + ids[i+1..];
                continue;
            }
            temp_map = moneyob->QueryMoney() || ([]);
            if (moneyob != MONEY_LIB->QueryMoneyObject(TP))
            // dinero no válido
            {
                no_ingresado += ({CAP(ids[i]) + " no es válido"});
                ids = ids[.. i -1] + ids[i+1..];
                continue;
            }
            // Reunificamos el dinero para evitar el bug de las multiplicidades.
            // Enserio, me pregunto como alguien puede darse cuenta de estos bugs XD
            moneyob->reunify_money();

            // quitamos los valores ceros que pueda haber en alguna de las
            // claves del array
            temp_map = filter_indices(temp_map,
                      lambda(({SYM(coin)}),({SF([),temp_map,
                      SYM(coin)})));
            
            if (!money_value = MONEY_DEMON->QueryMoneyValue(temp_map))
            // dinero sin valor
            {
                no_ingresado += ({CAP(ids[i]) + " no tiene valor"});
                ids = ids[.. i -1] + ids[i+1..];
                continue;
            }
            walk_mapping(temp_map, (:$3[$1] += $2:), &money_map);
            amount+=money_value;
            MONEY_LIB->PayMoney(TP,temp_map);
        }
    }
    if (sizeof(no_ingresado))
    {
        write(implode(no_ingresado,".\n") + ".\n");
    }
    if (!amount)
    {
        return notify_fail("No ingresas nada.\n",NOTIFY_NOT_VALID);
    }

    if (!BANKOBJECT->AddAccount(UID(TP), pBankName, amount-CalcFee(amount)))
    {
        return notify_fail("Error al ingresar dinero en tu cuenta bancaria. Por "
                           "favor, contacta cuanto antes con un wizard.\n",
                           NOTIFY_NOT_VALID);
    }
    if (str != "todo" && str != "dinero")
    {
        str = implode(ids[0..<2], ", ") + (sizeof(ids) > 1 ? " y " : "") + ids[<1];
    }

    play_sound(environment(TP), SND_SUCESOS("dinero"));
    write("Ingresas " + str + " en el Banco y pagas una comisión de " +
        MONEY_LIB->Value2String(CalcFee(amount)) + ".\n"
        "Tu saldo actual es de " + get_amount(UID(TP)) + ".\n");
    say(CAP(TNAME) + " habla con " + KeeperName(K_CAP) + ".\n");
    return 1;
}
public varargs int get_amount_money(int amnt, string type, string other_bank)
{
    mapping dummy = ([]);
    
    filter(m_indices(MONEY_DEMON->QueryCoinTypes()),
        lambda(({SYM(typ), SYM(map)}),
        ({SF(=), ({SF([), SYM(map), SYM(typ)}), 1})),
        dummy);

    if(!member(MONEY_DEMON->QueryCoinTypes(), type))
    {
        type = MONEY_DEMON->PresentMoney(type,dummy);
    }
    if(!type)
    {
        return notify_fail("Lo siento, no trabajamos con esa moneda.\n",
            NOTIFY_NOT_VALID);
    }

    if (amnt > __INT_MAX__ / MONEY_DEMON->QueryCoinValue(type))
    // esa multiplicación daría overflow
    {
        return notify_fail(KeeperName(K_CAP) + " te dice: Lo siento, pero no "
            "tienes tanto dinero en " + (other_bank ? "esa" : "esta") + " cuenta. Actualmente "
            "tienes " +
            (other_bank ? MONEY_LIB->Value2String(BANKOBJECT->QueryAccount(TNREAL, other_bank)[A_AMOUNT]) :
            get_amount(getuid(TP))) + ".\n", NOTIFY_NOT_VALID);
    }

    return amnt*MONEY_DEMON->QueryCoinValue(type);
}

        

private int _withdraw_other_bank(mixed amnt, string type, string bank)
{
    mixed *bankinfo;
    int value, value2;

    if (QueryCloseInformed())
    // si vamos a cerrar, no se realizan operaciones
    {
        return notify_fail(KeeperName(K_CAP) + " te dice: Lo siento, pero estamos a punto de cerrar. "
                           "Para usar el servicio de recogida de dinero en otras oficinas, tendrás que "
                           "venir mañana.\n", NOTIFY_NOT_VALID);
    }
    if (!BANKOBJECT->HasAccount(TNREAL, pBankName))
    {
        return notify_fail(KeeperName(K_CAP) + " te dice: 'Lo siento, pero antes de sacar dinero "
                           "de otros bancos, tendrás que abrirte una cuenta en este'.\n", NOTIFY_NOT_VALID);
    }
    if (!BANKOBJECT->HasAccount(TNREAL, bank))
    {
        return notify_fail("No tienes cuenta en ese banco.\n");
    }
    
    bankinfo = BANKOBJECT->QueryBankInfo(bank);
    if (bankinfo && bankinfo[BANK_CLOSE] && member(bankinfo[BANK_CLOSE], QueryDayState()) >= 0)
    {
        say(KeeperName(K_CAP) + " mira unos papeles y le dice algo a " + CAP(TNAME) + ".\n");
        return notify_fail(KeeperName(K_CAP) + " consulta unos papeles y te dice: 'Lo siento, " +
                           CAP(TNAME) + ", pero el banco de " + CAP(bank) + " está cerrado "
                           "en este momento'.\n");
    }
    value2 = BANKOBJECT->QueryAccount(TNREAL, bank)[A_AMOUNT];
    if (amnt != "todo")
    {
        if (!value = get_amount_money(amnt, &type, bank)) return 0;
        if (value > value2)
        {
            return notify_fail("No tienes tanto dinero en esa cuenta.\n", NOTIFY_NOT_VALID);
        }
    }
    else value = BANKOBJECT->QueryAccount(TNREAL, bank)[A_AMOUNT];
    if (value < pFixedFeeTransfer)
    {
        return notify_fail(KeeperName(K_CAP) + " te dice: 'Lo siento " + CAP(TNAME) +
                           ", pero la cantidad mínima que te permitimos traer de otros bancos, es de " + MONEY_LIB->Value2String(pFixedFeeTransfer) + "'.\n", NOTIFY_NOT_VALID);
    }
    if (CalcFeeTransfer(value) > value2)
    {
        return notify_fail(KeeperName(K_CAP) + " te dice: No tienes suficiente dinero en tu "
                           "cuenta para sacar esa cantidad y pagar la comisión por este servicio.\n",
                           NOTIFY_NOT_VALID);
    }
    say(KeeperName(K_CAP) + " le pregunta algo a " + CAP(TNAME) + ".\n");
    input_to("_confirm_transfer", INPUT_PROMPT,
             KeeperName(K_CAP) + " te dice: 'La comisión por recoger esta cantidad, es de " +
             MONEY_LIB->Value2String(CalcFeeTransfer(value)) + ". ¿Deseas continuar? Pulsa s, o n'. ",
             amnt, type, bankinfo && bankinfo[BANK_PATH] ? bankinfo[BANK_PATH] : 0, bank, value, value2);
    return 1;
}

public void _confirm_transfer(string str, mixed amnt, string type, string path, string bank, int value, int value2)
{
    object keeper, p;
    int kgender;
    if (!str || member(({"s", "si", "sí", "n", "no"}), (str = LOWER(str))) < 0)
    {
        write("Debes pulsar s, o n.\n");
        input_to("_confirm_transfer", INPUT_PROMPT,
                 KeeperName(K_CAP) + " te dice: 'La comisión por recoger esta cantidad, es de " +
                 MONEY_LIB->Value2String(CalcFeeTransfer(value)) + ". ¿Deseas continuar? Pulsa s, o n'. ",
                 amnt, type, path, bank, value, value2);
        return;
    }
    if (str == "n" || str == "no")
    {
        write(KeeperName(K_CAP) + " te dice: 'Bien, como quieras'.\n");
        KeeperEmote(({0, "se encoge de hombros con indiferencia.\n"}));

        return;
    }
    keeper = QueryKeeper();
    kgender = !keeper ? GENDER_MALE : keeper->QueryGender();
    write(KeeperName(K_CAP) + " te dice: 'De acuerdo, vamos a ello'.\n");
    KeeperEmote("se levanta de detrás del mostrador mientras dice: '" +
                (sizeof(filter(all_inventory(), SF(query_once_interactive))) > 1 ? "'Disculpen un minuto, "
                "enseguida vuelvo.'" : "No te muevas de aquí, " + CAP(TNREAL) + ". Enseguida estoy de vuelta'.") +
                "\nLuego, ves cómo se concentra intensamente, y "
                "Al instante, aparece una puerta dimensional que " +
                (kgender == GENDER_MALE ?
                 "el banquero" : "la banquera") +
                " atraviesa rápidamente.\nLa puerta se cierra y desaparece.\n");
    play_sound(TO, SND_MAGIA("puerta"));
    if (keeper) keeper->move(ROOM);
    else SetNoKeeper(0); // para que no atienda mientras no está
    if (path && (p = find_object(path)))
    {
        tell_room(p, "Se abre una puerta dimensional y ves aparecer a" +
            (kgender == GENDER_MALE ? "l banquero" : " la banquera") +
            " de la oficina de " + CAP(pBankName) + ".\n" +
            (kgender == GENDER_MALE ? "El banquero" : "La banquera") +
            " habla con " + p->KeeperName(K_CAP) + ", " +
            (!p->QueryKeeper() || p->QueryKeeper()->QueryGender() == GENDER_MALE ? "el" : "la") +
            "cual consulta unos papeles y le "
            "da algo de dinero. Tras un saludo a todos, " +
            (kgender == GENDER_MALE ? "el" : "la") +
            "visitante "
            " vuelve a atravesar la puerta, que desaparece rapidamente.\n");
        play_sound(p, SND_MAGIA("puerta"));
    }
    call_out("_goto_other_bank", 20, NREAL(TP), amnt, type, keeper, bank, value, value2);
}

public void _goto_other_bank(string pl, mixed amnt, mixed type, object keeper, string bank, int value, int value2)
{
    object plob;
    int remaining = value2 - value, quitado;
    mapping m_money;
    
    plob = find_object(pl);
    if (amnt == "todo")
    {
        amnt = value;
        type = m_indices(MONEY_DEMON->QueryCoinTypes());
    }
    else
    {
        amnt = amnt * MONEY_DEMON->QueryCoinValue(type);
    }

    remaining -= CalcFeeTransfer(value);
    if (remaining < 0)
    // no hay suficiente pasta restante en la cuenta para cobrar la comisión, así que la
    //cobramos del dinero que le vamos a dar al player
    {
        quitado = 1;
        value += remaining;
        remaining = 0;
        amnt = value;
        if (stringp(type)) type = m_indices(MONEY_DEMON->QueryCoinTypes());
    }

        if (!keeper) SetNoKeeper(1);
    else keeper->move(TO);
    play_sound(TO, SND_MAGIA("puerta"));
    tell_room(TO, "Se abre una puerta dimensional y ves aparecer a " + KeeperName(K_CAP) + ".\n"
              "La puerta se cierra y desaparece.\n");
    if (!plob || !present(plob, TO))
    {
        KeeperEmote("mira hacia todos lados como si buscara a alguien. Luego, refunfuñando "
            "con cara malhumorada, abre un armario y "
                    "deposita en él algo de dinero que llevaba entre las manos.\n"
                    "-Estos clientes, ¡Siempre con prisas! -Le oyes murmurar por lo bajo, mientras se acomoda en su sillón.\n");
        BANKOBJECT->AddAccount(pl, pBankName, value);
        BANKOBJECT->SetAccount(pl, bank, remaining);
    }
    else
    {
        m_money = MONEY_DEMON->CreateMoney(amnt, pointerp(type) ? type : ({type}));
        tell_object(plob, KeeperName(K_CAP) + " te da " +
            MONEY_LIB->Mapping2String(m_money) + 
            (quitado ? " mientras te dice: 'He tenido que quitar algo de dinero de lo que "
            "me has pedido para cobrarte la comisión por transferencias, pues en la cuenta de " +
            CAP(bank) + " ya no quedaba suficiente'" : "") +
            ".\n");
        tell_room(TO, KeeperName(K_CAP) + " le da algo de dinero a " + CAP(NNAME(plob)) + ".\n", ({plob}));
        MONEY_LIB->AdjustMoney(plob, m_money);
        KeeperEmote("guarda algo de dinero en un gran armario, y a continuación, vuelve a sentarse "
            "tras el mostrador.\n");
        BANKOBJECT->SetAccount(NREAL(plob), bank, remaining);
    }
}



public int cmd_withdraw(string str)
{
    int how_much, i, remaining;
    string type, bank;
    mixed *values, amnt;
    
    if (   !str || str == "?" || str != "todo"
        && sscanf(str, "%d %s de %s", amnt, type, bank) != 3
        && sscanf(str, "%s de %s", amnt, bank) != 2
        && sscanf(str, "%d %s", amnt, type) != 2)
    {
        return notify_fail("Uso: sacar todo, sacar <dinero> <moneda>, sacar todo de <banco>, "
            "o sacar <dinero> <moneda> de <banco>.\n",
                           NOTIFY_ILL_ARG);
    }
    if (!Named()) return 0;
    // si no puede atender al player...
    if (CantAttend(K_NOTIFY)) return 0;
    if (bank && bank != pBankName)
    // va a sacar dinero de otro banco
    {
        return _withdraw_other_bank(amnt, type, bank);
    }
    if (!HasAccount()) return 0;
    // antes de hacer nada, comprobamos si el player tiene dinero en el banco
    remaining = BANKOBJECT->QueryAccount(UID(TP), pBankName)[A_AMOUNT];
    if (!remaining)
    {
        return notify_fail(KeeperName(K_CAP) + " te dice: No tienes "
                           "dinero en tu cuenta.\n", NOTIFY_NOT_VALID);
    }

    if (str == "todo")
    // sacamos todo el dinero que tenga en el banco
    {
        BANKOBJECT->AddAccount(UID(TP), pBankName, -remaining);
        MONEY_LIB->AdjustMoney(TP,MONEY_DEMON->CreateMoney(remaining,
                                                           MONEY_LIB->QueryValuta()));
    }
    // saca otro tipo de monedas
    else
    {
        if (amnt<=0)
        {
            return notify_fail("¿No quieres sacar nada?.\n", NOTIFY_NOT_VALID);
        }

        if (!how_much = get_amount_money(amnt, &type)) return 0;
        if (!BANKOBJECT->AddAccount(UID(TP), pBankName, -how_much))
        {
            return notify_fail(KeeperName(K_CAP) + " te dice: No tienes "
                               "suficiente dinero en tu cuenta.\n",
                               NOTIFY_NOT_VALID);
        }
        MONEY_LIB->AdjustMoney(TP,MONEY_DEMON->CreateMoney(how_much,({type})));
    }

    say(CAP(TNAME) + " le pide dinero a " + KeeperName(K_CAP) + ".\n");
    play_sound(environment(TP), SND_SUCESOS("dinero"));
    KeeperEmote(({"abre un gran armario, abre una caja de acero "
                  "templado y saca de ella el dinero que le has pedido. Luego "
                  "vuelve a cerrar la caja y el armario.\n"
                  "Tu saldo actual es de " + get_amount(UID(TP)) + ".\n",
                  "abre un gran armario, abre una caja de acero templado, y "
                  "le da a " + CAP(TNAME) + " el dinero que había pedido. A "
                  "continuación, cierra la caja y el armario.\n"}));
    return 1;
}

public int cmd_balance(string str)
{
    mixed *acc;
    string pl_uid; // como uso varias veces el euid, lo almaceno en una variable

    if (str)
    {
        return notify_fail("Para comprobar el estado de la cuenta, escribe "
                           "'balance', sin parámetros.\n",
                           NOTIFY_ILL_ARG);
    }
    if (!Named()) return 0;
    if (CantAttend(K_NOTIFY)) return 0;
    if (!HasAccount()) return 0;
    if (!(acc = BANKOBJECT->QueryAccount(UID(TP), pBankName)))
    {
        KeeperTell("Tu cuenta está vacía.\n");
        return 1;
    }

    pl_uid = UID(TP);
    KeeperTell("Actualmente tienes " +
      	       MONEY_LIB->Value2String(acc[A_AMOUNT],
      	       MONEY_LIB->QueryValuta()) + " en tu cuenta.\n"
	           "Creada:                   " + get_date(acc[A_CREATED]) +
	           "\nÚltimo ingreso:           " + get_date(acc[A_DEPOSIT]) +
	           "\nÚltimo reintegro:         " + get_date(acc[A_WITHDRAW]) +
	           "\n");
    say(CAP(TNAME) + " habla con " + KeeperName(K_CAP) + ".\n");
    return 1;
}

public int cmd_kick(string str)
{
    if (!str || !QueryKeeper() || QueryKeeper() != present(str)) return 0;

    say(CAP(TNAME) + " intenta abalanzarse sobre " + KeeperShort() + ", pero "
        "se da de narices contra unos barrotes metálicos.\n");
    write("Te abalanzas furios" + TP->QueryGenderEndString() + " sobre " +
          KeeperShort() + ", pero te das con los huesos en los dolorosos "
          "barrotes metálicos que le "
      	  "protegen.\n");
    return 1;
}

public int cmd_steal(string str)
{
    if (!str || !QueryKeeper()) return 0;
    if (str[0..1] == "a ") str = str[2..];
    if (QueryKeeper() != present(str)) return 0;

    say(CAP(TNAME) + " intenta robarle a" + KeeperShort() + ". sin demasiado "
        "éxito.\n");
    write(KeeperName(K_CAP) + " está dentro de una ventanilla con barrotes... "
          "La verdad es que sería curioso ver como te las apañarías para "
          "robarle.\n");
    return 1;
}


public int cmd_folleto(string str)
{
    object ob;
    if (!pLeaflets || str != "folleto" || present(str)) return 0;
    if (!num_folletos)
    {
        return notify_fail("No quedan folletos en la caja.\n",
                           NOTIFY_NOT_VALID);
    }

    ob = clone_object("/std/bancos/folleto_banco");
    if (ob->move(TP,M_GET) != ME_OK)
    {
        ob->remove();
        return notify_fail("Intentas coger un folleto pero te es imposible.\n",
                           NOTIFY_NOT_VALID);
    }
    write("Recoges un folleto.\n");
    say(CAP(TNAME) + " recoge un folleto de la caja.\n");

    num_folletos--;
    return 1;
}

public void reset()
{
    int transfering = find_call_out("_goto_other_bank");
    if (transfering >= 0)
    {
        call_out("reset", transfering + 2);
        return;
    }
    ::reset();
    // llenamos la caja de folletos
    num_folletos = FOLLETOS;
}

public varargs SetKeeper(mixed arg1, mixed arg2)
// sobrecargamos esta función para meterle un par de propiedades
// de seguridad al banquero, para que sea imposible matarlo
{
    object keeper;
    ::SetKeeper(arg1, arg2);
    if (keeper = QueryKeeper())
    {
        keeper->Set(P_CANT_FIGHT,1);
        keeper->Set(P_CANT_STEAL,1);
    }
}

public int *SetCloseTime(mixed time)
{
    int *res = ::SetCloseTime(time);
    BANKOBJECT->RegisterBank(pBankName, object_name(), QueryCloseTime());
    return res;
}


//