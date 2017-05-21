#include <wizlevels.h>



private int _banear(string str)
{
    string nombre, razon, fecha;
    int hasta;

    if (!IS_ARCH(TI))
    {
        return notify_fail("No tienes permiso para hacer esto.\n", NOTIFY_NOT_VALID);
    }


    if (  !str
        || !strlen(str)
        || (   sscanf(str, "%s porque %s hasta %s", nombre, razon, fecha) != 3
            && sscanf(str, "%s porque %s", nombre, razon) != 2)
        ||!nombre
       )
    {
        return notify_fail("Uso: nicks banear <nombre> porque <razón>, o "
            "banear <nombre> porque <razon> hasta <fecha (DD/MM/AAAA [HH:MM:SS])>\n", NOTIFY_NOT_VALID);
    }


    // [Nyh] La siguiente comprobación es estúpida, ya que cualquiera que pueda
    //       usar este comando tiene derechos de escritura para modificarlo.
    if (query_wiz_level(nombre) >= query_wiz_level(TI)) {
        return notify_fail("No puedes banear a alguien con mayor o igual nivel que tú.\n", NOTIFY_NOT_VALID);
    }

    seteuid(getuid());
    if (fecha && !hasta = DATE->get_timestamp(fecha))
    {
        return notify_fail("Fecha no válida. Recuerda, debe cumplir el formato DD/MM/AAAA.\n",
                           NOTIFY_NOT_VALID);
    }
    return CHARMASTER->BanName(nombre, razon, hasta);
}



private int _desbanear(string str)
{
    if (!IS_ARCH(TI))
    {
        return notify_fail("NO tienes permisos para hacer esto.\n",
                           NOTIFY_NOT_VALID);
    }


    if (!str || !strlen(str)) return notify_fail("Uso: nicks desbanear <nombre>\n", NOTIFY_NOT_VALID);
    return CHARMASTER->UnbanName(str);
}


public int main(string str)
{
    string *palabras, opcion, args;
    if (!str)
    {
        return notify_fail("Opciones de nicks: aceptar, rechazar, pendientes, banear, desbanear y comprobar.\n",
                           NOTIFY_NOT_VALID);
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

