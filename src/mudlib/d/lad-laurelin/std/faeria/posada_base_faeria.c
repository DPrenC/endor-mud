/***
Archivo: posada_base_faeria.c
Autor: kastwey@simauria
Descripción: Habitación base para la posada de faeria.
Incluye las funciones de reiniciar y del prevent_leave...
Pa que no se escapen con la llave :)
***/

#include "path.h"
#include <moving.h>

inherit STD_FAERIA("hab_siempreunidos");

int cmd_reiniciar();

init()
{
    ::init();
    add_action("cmd_reiniciar", "reiniciar");
}

public int prevent_leave(mixed dest, int method, mixed extra)
{
    if ((method == M_TELEPORT || (method == M_SILENT && extra == 0)) && present("llave_posada_faeria", TP))
{
        write("Cuando vas a teletransportarte, te das cuenta de que aún conservas la llave de la posada... Sería mejor devolvérsela antes al posadero, no sea que se enfade.\n");
        return ME_NO_LEAVE;
    }
    else
    {
        return ::prevent_leave(dest, method, extra);
    }
}

int cmd_reiniciar()
{
    object libro;
    if (!present("llave_posada_faeria", TP)) return 0;
    libro = clone_object(OBJ_OTRO_FAERIA("libro_habitaciones"));
    libro->RemoveHuesped(TP->QueryRealName());
    present("llave_posada_faeria", TP)->remove();
    return 0;
}
