/*
 * simauria /bin/wiz/_nicks.c
 */


#include <characters.h>

private int _pendientes()
{
    return CHARMASTER->CheckPendingNames(CH_PROMPT);
}


private int _aceptar(string args)
{
    int res;
    res = CHARMASTER->AcceptName(args);
    if (!res) return 0;
    write("Has aceptado el nombre '" + args + "'.\n");
    return 1;
}

private int _rechazar(string args)
{
    int res;
    string nombre, razon;
    if (sscanf(args, "%s porque %s", nombre, razon) != 2)
    {
        return notify_fail("Sintaxis: nicks rechazar <nombre> porque <razón>.\n");
    }
    res = CHARMASTER->RejectName(nombre, razon);
    if (!res) return 0;
    write("Has rechazado el nombre " + nombre + "'.\n");
    return 1;
}

private int _comprobar(string args)
{
    mixed *res;
    if (!args || !strlen(args)) return notify_fail("Debes introducir el nombre a comprobar.\n");
    write("Estado del nombre '" + args + "'.\n");
    if ((res = CHARMASTER->QueryBanishedName(args, CH_INFO))[CH_STATUS] == NICK_BANISHED)
    // está baneado
    {
        int until;
        write("Este nombre fue baneado por " + CAP(res[CH_INFO][N_BAN_WIZ]) + ", el " +
              STR->etime(1, ctime(to_int(res[CH_INFO][N_BAN_DATE]))) + " " +
              ((until = to_int(res[CH_INFO][N_BAN_UNTIL])) ? "hasta el " +
               STR->etime(1, ctime(until)) : " por tiempo indefinido") +
              ".\n");
        return 1;
    }
    res = CHARMASTER->QueryValidName(args, CH_INFO, CH_FORCE_CHECK);
    switch(res[CH_STATUS])
    {
        case NICK_VALID:
             write("Nick aceptado por " + CAP(res[CH_INFO][N_WIZ]) + ", el " +
                   STR->etime(1, ctime(to_int(res[CH_INFO][N_DATE]))) + ".\n");
             return 1;
             break;
        case NICK_INVALID:
             write("Nick rechazado por " + CAP(res[CH_INFO][N_WIZ]) + ", el " +
                   STR->etime(1, ctime(to_int(res[CH_INFO][N_DATE]))) + ". Razón: " +
                   res[CH_INFO][N_REASON] + ".\n");
             return 1;
             break;
        case NICK_PENDING:
             write("Nick pendiente de aprobación, desde el " +
                   STR->etime(1, ctime(to_int(res[CH_INFO][N_DATE]))) + ".\n");
             return 1;
             break;
        case NICK_UNKNOWN:
             write("Este nombre no existe en la base de datos.\n");
             return 1;
             break;
    }
    return notify_fail("Estado desconocido para ese nick.\n", NOTIFY_NOT_VALID);
}

public int main(string str)
// función principal.
// las opciones disponibles son: aceptar, rechazar, comprobar o pendientes.
{
    string opcion, *palabras, args;;
    if (!str)
    {
        return notify_fail("OPciones de nicks: aceptar, rechazar, comprobar o pendientes.\n");
    }
    palabras = explode(str, " ");
    opcion = palabras[0];
    args = implode(palabras[1..], " ");

    switch(opcion)
    {
        case "pendientes": return _pendientes(); break;
        case "aceptar": return _aceptar(args); break;
        case "rechazar": return _rechazar(args); break;
        case "comprobar": return _comprobar(args); break;
        default:
             return notify_fail("Opciones de nicks: aceptar, rechazar, comprobar o pendientes.\n");
             break;
    }
    return 0;
}

