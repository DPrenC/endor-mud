/***
Fichero: pasillos_base.c
Autor: kastwey@simauria
Descripción: Fichero base de los pasillos.
Creación: 14/12/2004
***/

#include "path.h"
#include <moving.h>

inherit STD_FAERIA("hab_siempreunidos");

int cmd_coger(string str);

create()
{
    ::create();
    SetIntShort("un pasillo en las celdas");
    SetIntLong(W("Te encuentras andando por el pasillo que recorre la sala de las celdas de este a oeste.\n"
    "La humedad ha hecho que por todas partes esté presente una gruesa capa de musgo que lo cubre todo.\n"));
    SetIndoors(1);
    SetIntBright(20);
    AddDetail(({"celdas", "celda"}), "Son unas celdas alineadas en una de las paredes de la sala. Tienen una puerta de barrotes, pero todas están abiertas.\n");
    SetIntSmell("Huele mal... Es una mezcla entre humedad y suciedad acumulada.\n");
    SetIntNoise("Escuchas el ruido de bichos correteando... Mejor no pensar que se esconde por los rincones de este tétrico lugar.\n");
    AddDetail(({"musgo", "pared", "paredes", "techo", "suelo"}), "Tanto las paredes como suelo y techo de la sala, están recubiertos por una gruesa capa de musgo.\n");
}

public int prevent_leave(mixed dest, int method, mixed extra)
{
    // debug    tell_object(find_object("kastwey"), to_string(method) + "\n" + to_string(extra) + ".\n" + PO->QueryName() + ".\n");
    if (!query_wiz_level(PO) && (method == M_TELEPORT || (method == M_SILENT && !extra)))
    {
        write("Una fuerza mágica impide que realices el teletransporte.\n");
        return ME_NO_LEAVE;
    }
    else
    {
        return ::prevent_leave(dest, method, extra);
    }
}

init()
{
    ::init();
    add_action("cmd_coger", "coger");
}


int cmd_coger(string str)
{
    string *palabras;
    if (!str || (str != "musgo de techo" && str != "musgo del techo" && str != "musgo de pared" && str != "musgo de la pared" && str != "musgo")) return 0;
    palabras = explode(str, " ");
    switch(palabras[sizeof(palabras)-1])
    {
        case "techo":
            write("El techo está demasiado alto para que puedas coger musgo de él.\n");
            break;
        case "pared":
            write("Intentas arrancar un trozo de musgo de la pared, pero está tan firmemente sujeto que te es imposible coger nada.\n");
            break;
        default:
            write("Intentas arrancar un trozo de musgo de la pared, pero está tan firmemente sujeto que te es imposible coger nada.\n");
            break;
    }
    return 1;
}
