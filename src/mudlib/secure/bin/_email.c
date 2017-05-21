/*
 * simauria /secure/bin/_email
**/

#include <wizlevels.h>

private int _banear(string str)
{
    string email, razon, fecha;
    int hasta;

    if (!IS_ARCH(TI))
    {
        return notify_fail("No tienes permiso para hacer esto.\n", NOTIFY_NOT_VALID);
    }


    if (  !str
        || !strlen(str)
        || (   sscanf(str, "%s porque %s hasta %s", email, razon, fecha) != 3
            && sscanf(str, "%s porque %s", email, razon) != 2)
        ||!email
       )
    {
        return notify_fail("Uso: email banear <email> porque <razón>, o "
            "banear <email> porque <razon> hasta <fecha (DD/MM/AAAA [HH:MM:SS])>\n", NOTIFY_NOT_VALID);
    }
    
    seteuid(getuid());
    if (fecha && !hasta = DATE->get_timestamp(fecha))
    {
        return notify_fail("Fecha no válida. Recuerda, debe cumplir el formato DD/MM/AAAA.\n",
                           NOTIFY_NOT_VALID);
    }
    return CHARMASTER->BanEmail(email, razon, hasta);
}



private int _desbanear(string str)
{
    if (!IS_ARCH(TI))
    {
        return notify_fail("NO tienes permisos para hacer esto.\n",
                           NOTIFY_NOT_VALID);
    }


    if (!str || !strlen(str)) return notify_fail("Uso: nicks desbanear <email>\n", NOTIFY_NOT_VALID);
    return CHARMASTER->UnbanEmail(str);
}


public int main(string str)
{
    string *palabras, opcion, args;
    if (!str)
    {
        return 0;
    }
    palabras = explode(str, " ");
    opcion = palabras[0];
    args = implode(palabras[1..], " ");

    switch(opcion)
    {
        case "banear": return _banear(args); break;
        case "desbanear": return _desbanear(args); break;
    }
    return 0;
}

