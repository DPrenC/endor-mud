/**
 * simauria /bin/wiz/_email
**/

#include <characters.h>

private int comprobar(string str)
{
    mixed *info;
    
    if (!str || str == "")
    {
        return notify_fail("Sintaxis: email comprobar <dirección>\n",
                           NOTIFY_NOT_VALID);
    }
    info = CHARMASTER->QueryBanishedEmail(str, CH_INFO);
    if (!info[CH_STATUS])
    {
        write("Ese e-mail no está baneado" + (!MASTER->mail_exists(str) ? ", ni se encuentra "
            "registrado por ningún personaje.\n" : "") + ".\n");
        return 1;
    }
    write("E-mail baneado por " + CAP(info[CH_INFO][E_BAN_WIZ]) +
        ", el " + STR->etime(1, ctime(info[CH_INFO][E_BAN_DATE])) +
        (info[CH_INFO][E_BAN_UNTIL] ? " hasta el " + STR->etime(1, ctime(info[CH_INFO][E_BAN_UNTIL])) : "") +
        ".\n");
    return 1;
}


public int main(string str)
{
    string *palabras;
    if (!str) return 0;
    palabras = explode(str, " ");
    if (palabras[0] != "comprobar")
    {
        return notify_fail("Sintaxis: email <nueva_direccion>, o comprobar.\n");
    }

    return comprobar(implode(palabras[1..], " "));
}