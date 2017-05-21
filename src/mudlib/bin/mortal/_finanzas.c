/**
 * simauria/bin/mortal/_finanzas
**/

#include <money.h>

public int main(string str)
{
    string banco;
    int i;

    seteuid(getuid());
    if (!str || str == "breve")
    // finanzas generales
    {
        mixed chaccounts = BANKOBJECT->QueryAccounts(TNREAL);
        int sz, total;
        string lista;

        if (!(sz = sizeof(chaccounts[0])))
        {
            return notify_fail("No tienes cuenta en ningún banco.\n", NOTIFY_NOT_VALID);
        }
        if (str == "breve")
        {
            lista = "Estado abreviado de tus finanzas.\n\n" + sprintf("%-20s| cantidad\n", "Banco");
            for (i=0;i<sz; i++)
            {
                lista += sprintf("%-20s| %-50s\n", CAP(chaccounts[0][i]), MONEY_LIB->Value2String(chaccounts[1][i], 1) + ".");
                total += chaccounts[1][i];
            }
            lista += sprintf("%-20s| %-50s\n", "Total", MONEY_LIB->Value2String(total, 1));
            total = 0;
            STR->smore(lista, TP->QueryPageSize());
            return 1;
        }
        lista = "Estado de tus finanzas:\n";
        for (i=0;i<sz; i++)
        {
            lista += CAP(chaccounts[0][i]) + ": " + MONEY_LIB->Value2String(chaccounts[1][i]) + ".\n";
            total += chaccounts[1][i];
        }
        lista += "Saldo total en la red de bancos de Simauria: " + MONEY_LIB->Value2String(total) + ".\n";
        total = 0;
        STR->smore(lista, TP->QueryPageSize());
        return 1;
    }
    else if (str && sscanf(str, "de %s", banco) == 1)
    {
        string *maccount = BANKOBJECT->QueryAccount(TNREAL, banco);
        string mensaje;

        if (!maccount || !sizeof(maccount))
        {
            return notify_fail("No tienes cuenta en ese banco.\n", NOTIFY_NOT_VALID);
        }
        mensaje = "Información de la cuenta del banco de " + CAP(banco) + ":\n"
                  "Balance: " + MONEY_LIB->Value2String(maccount[A_AMOUNT]) +
                  ". Creada: " +
                  (!maccount[A_CREATED] ? "No hay datos" : STR->etime(0, ctime(to_int(maccount[A_CREATED])))) +
                  ". Último ingreso: " +
                  (!maccount[A_DEPOSIT] ? "No hay datos" : STR->etime(0, ctime(to_int(maccount[A_DEPOSIT])))) +
                  ". Último reintegro: " + (!maccount[A_WITHDRAW] ? "No hay datos" : STR->etime(0, ctime(to_int(maccount[A_WITHDRAW])))) +
                  ".\n";
        write(mensaje);
        return 1;
    }
    else
    {
        return notify_fail("Uso: finanzas: Te muestra el estado de todas tus cuentas.\n"
                           "finanzas breve: Te muestra información en formato breve sobre todas tus cuentas.\n"
                           "finanzas de <banco>: Te muestra información sobre la cuenta del banco <banco>.\n");
    }
}
