/**
* simauria bin/wiz/_finanzas
**/

#include <money.h>
#include <sounds.h>

private int _not_found(string jugador)
{
    play_sound(TP, SND_SUCESOS("comando_error"));
    return notify_fail("No se encontró " +
                       (MASTER->find_userinfo(jugador) ? "la cuenta especificada" : "el jugador especificado") +
                       ".\n", NOTIFY_NOT_VALID);
}

private int _accounts_info(string jugador)
{
    mixed chaccounts = BANKOBJECT->QueryAccounts(jugador = LOWER(jugador));
    int sz, total, i;
    string lista;

    if (!chaccounts || !(sz = sizeof(chaccounts[0])))
    {
        if (MASTER->find_userinfo(jugador))
        {
            play_sound(TP, SND_SUCESOS("comando_info"));
            return notify_fail("Ese jugador no tiene cuenta en ningún banco.\n",
                NOTIFY_NOT_VALID);
        }
        play_sound(TP, SND_SUCESOS("comando_error"));
        return notify_fail("No se encontró el jugador especificado.\n", NOTIFY_NOT_VALID);
    }
    lista = "Estado de las finanzas de " + CAP(jugador) + ":\n";
    for (i=0;i<sz; i++)
    {
        lista += CAP(chaccounts[0][i]) + ": " + MONEY_LIB->Value2String(chaccounts[1][i]) + ".\n";
        total += chaccounts[1][i];
    }
    lista += "Saldo total en la red de bancos de Simauria: " + MONEY_LIB->Value2String(total) + ".\n";
    total = 0;
    play_sound(TP, SND_SUCESOS("comando_info"));
    STR->smore(lista, TP->QueryPageSize());
    return 1;

}

private int _account_info(string jugador, string banco)
{
    mixed *maccount = BANKOBJECT->QueryAccount(jugador = LOWER(jugador), banco);
    string mensaje;

    if (!maccount || !sizeof(maccount))
    {
        return _not_found(jugador);
    }
    mensaje = "Información de la cuenta de " + CAP(jugador) + ", del banco de " + CAP(banco) + ":\n"
        "Balance: " + MONEY_LIB->Value2String(maccount[A_AMOUNT]) +
        ". Creada: " +
        (!maccount[A_CREATED] ? "No hay datos" : STR->etime(0, ctime(to_int(maccount[A_CREATED])))) +
        ". Último ingreso: " +
        (!maccount[A_DEPOSIT] ? "No hay datos" : STR->etime(0, ctime(to_int(maccount[A_DEPOSIT])))) +
        ". Último reintegro: " + (!maccount[A_WITHDRAW] ? "No hay datos" : STR->etime(0, ctime(to_int(maccount[A_WITHDRAW])))) +
        ".\n";
    play_sound(TP, SND_SUCESOS("comando_info"));
    write(mensaje);
    return 1;
}

private int _lista_mejores()
{
    mixed res = BANKOBJECT->Top(0, 10);
    int i, sz;
    string msg;

    if (!res || !(sz = sizeof(res[0])))
    {
        play_sound(TP, SND_SUCESOS("comando_info"));
        return notify_fail("No hay cuentas bancarias almacenadas.\n");
    }

    msg = "La lista de los 10 mejores clientes de la red bancaria de Simauria:\n";
    for(i=0;i<sz; i++)
    {
        msg += CAP(res[0][i]) + ": " + MONEY_LIB->Value2String(res[1][i]) + ".\n";
    }
    play_sound(TP, SND_SUCESOS("comando_info"));
    write(msg);
    return 1;
}

public int main(string str)
{
    string jugador, banco;
    int cantidad;
    seteuid(getuid());
    str = LOWER(str || "");
    switch(str)
    {
        case "info":
            return notify_fail("uso: finanzas info <jugador>: Obtiene información general sobre "
                               "las finanzas del jugador <jugador.\nfinanzas info <jugador> <banco>: "
                               "Obtiene información sobre la cuenta del jugador <jugador> del banco <banco>.\n",
                               NOTIFY_NOT_VALID);
            break;
        case "ajusta":
            return notify_fail("Uso: finanzas ajusta <jugador> <banco> <dinero>: Modifica la cantidad de "
                               "dinero en el banco <banco> para el jugador <jugador>. El dinero debe ser "
                               "expresado en monedas de cobre.\n", NOTIFY_NOT_VALID);
            break;
        case "lista mejores":
            return _lista_mejores();
            break;
        case "elimina":
            return notify_fail("Uso: finanzas elimina <jugador> <banco>: Elimina la cuenta del "
                               "jugador <jugador> dle banco <banco>.\n"
                               "finanzas elimina <jugador>: Elimina todas lascuentas del jugador <jugador>.\n",
                               NOTIFY_NOT_VALID);
            break;
        case "modifica":
            return notify_fail("Uso: finanzas modifica <jugador> <banco> <cantidad>: Modifica la "
                               "cuenta del jugador <jugador> del banco <banco>, en la cantidad especificada "
                               "en <cantidad>, expresada en monedas de cobre. "
                               "Si la cantidad es positiva, se incrementará. De lo contrario, se reducirá.\n",
                               NOTIFY_NOT_VALID);
            break;
    }

    if (sscanf(str, "info %s %s", jugador, banco) == 2)
    // buscamos información sobre el jugador en el banco indicado
    {
        return _account_info(jugador, banco);
    }
    if (sscanf(str, "info %s", jugador) == 1)
    {
        return _accounts_info(jugador);
    }

    if (sscanf(str, "ajusta %s %s %d", jugador, banco, cantidad) == 3)
    {
    if (!MASTER->find_userinfo(jugador))
    {
            play_sound(TP, SND_SUCESOS("comando_error"));
            return notify_fail("No se encontró el jugador especificado.\n", NOTIFY_NOT_VALID);
        }
        if (!BANKOBJECT->SetAccount(jugador, banco, cantidad))
        {
            play_sound(TP, SND_SUCESOS("comando_error"));
            return notify_fail("Error al ajustar la cuenta del banco de " +
                               CAP(banco) + " para " + CAP(jugador) + ".\n", NOTIFY_NOT_VALID);
        }
        play_sound(TP, SND_SUCESOS("comando_hecho"));
        write("Cuenta modificada.\n");
        _account_info(jugador, banco);
        return 1;
    }
    if (sscanf(str, "modifica %s %s %d", jugador, banco, cantidad) == 3)
    // se modifica una cuenta
    {
        mixed *ac = BANKOBJECT->QueryAccount(jugador = LOWER(jugador), banco = LOWER(banco));
        int amnt, res;

        if (!ac)
        {
            return _not_found(jugador);
        }
        amnt = ac[A_AMOUNT];
        if (amnt + cantidad < 0)
        {
            play_sound(TP, SND_SUCESOS("comando_error"));
            return notify_fail("Esta operación, dejaría la cuenta de " + CAP(jugador) + " con un saldo "
                               "inferior a 0 monedas de cobre. Si deseas ponerla a 0, escribe "
                               "'finanzas reajusta " + jugador + " " + banco + " 0', o bien, puedes "
                               "cerrarle la cuenta con 'finanzas elimina " + jugador + " " + banco + "'.\n",
                               NOTIFY_NOT_VALID);
        }
        if (!BANKOBJECT->AddAccount(jugador, banco, cantidad))
        {
            play_sound(TP, SND_SUCESOS("comando_error"));
            return notify_fail("Error al modificar la cuenta de " + CAP(jugador) + ".\n",
                               NOTIFY_NOT_VALID);
        }
        play_sound(TP, SND_SUCESOS("comando_hecho"));
        write("Cuenta modificada.\n");
        _account_info(jugador, banco);
        return 1;
    }



        if (sscanf(str,"elimina %s %s", jugador, banco) == 2)
    {
        mixed *ac;
        int res;
        if (!(ac = BANKOBJECT->QueryAccount(jugador = LOWER(jugador), banco = LOWER(banco))))
        {
            return _not_found(jugador);
        }
        res = BANKOBJECT->CloseAccount(jugador, banco);
        if (res <= 0)
        {
            play_sound(TP, SND_SUCESOS("comando_error"));
            return notify_fail("Error al eliminar la cuenta de " + CAP(jugador) + " del banco de " +
                               CAP(banco) + ".\n", NOTIFY_NOT_VALID);
        }
        play_sound(TP, SND_SUCESOS("comando_hecho"));
        write("Cuenta eliminada.\n");
        return 1;
    }
    if (sscanf(str, "elimina %s", jugador) == 1)
    {
        int num;
        if (!MASTER->find_userinfo(jugador = LOWER(jugador)))
        {
            play_sound(TP, SND_SUCESOS("comando_error"));
            return notify_fail("No se encontró al jugador " + CAP(jugador) + ".\n", NOTIFY_NOT_VALID);
        }
        num = BANKOBJECT->CloseAccounts(jugador);
        if (num == -1)
        {
            play_sound(TP, SND_SUCESOS("comando_error"));
            return notify_fail("Error al eliminar la cuenta de " + CAP(jugador) + ".\n",
                               NOTIFY_NOT_VALID);
        }
        play_sound(TP, SND_SUCESOS("comando_hecho"));
        write(num + " cuentas eliminadas.\n");
        return 1;
    }
    return notify_fail("Uso:\nfinanzas: Te muestra información sobre tus finanzas.\n"
        "finanzas breve: Te muestra información breve sobre el estado de tus finanzas.\n"
        "finanzas de <banco>: Te muestra información detallada sobre tu cuenta del banco de <banco>.\n"
        "finanzas lista mejores: Lista de los 10 mejoresclientes de la red bancaria de Simauria.\n"
        "finanzas info <jugador>: Te muestra información sobre las finanzas del jugador <jugador>.\n"
        "finanzas info <jugador> <banco>: Te muestra información pormenorizada de la cuenta del "
        "jugador <jugador> del banco de <banco>.\n"
        "finanzas ajusta <jugador> <banco> <cantidad> (monedas de cobre): "
        "Ajusta la cuenta de <jugador> del banco <banco> a la cantidad especificada en <cantidad>, "
        "expresadas en monedas de cobre.\n"
        "finanzas elimina <jugador> <banco>: Elimina la cuenta del jugador <jugador> del banco <banco>.\n"
        "finanzas elimina <jugador>: Elimina todas las cuentas del jugador <jugador>.\n"
        "finanzas modifica <jugador> <banco> <cantidad> (monedas de cobre): "
        "Modifica la cantidad de la cuenta del jugador <jugador>, del banco <banco>, en los "
        "cobres especificados por <cantidad>, bien sean negativos (en cuyo caso se reducirán), bien "
        "positivos, en cuyo caso se incrementarán.\n",
        NOTIFY_NOT_VALID);
}