/****************************************************************************
Fichero: barril.c
Autor: Riberales
Fecha: 16/02/2006
Descripción: un barril en la arena de Annufam.
****************************************************************************/

#include "path.h"

inherit THING;

int b_vacio = 0;

public int cmd_beber(string str)
{
    if (!str || str != "agua") return notify_fail("¿Beber qué?\n", NOTIFY_NOT_VALID);;

    if (b_vacio == 10) return notify_fail("El barril está vacío.\n", NOTIFY_NOT_VALID);

    if (TP->QueryDrink() == TP->QueryMaxDrink())
    {
        return notify_fail("Ya no puedes beber más agua.\n", NOTIFY_NOT_VALID);
    }

    write("Te acercas al barril y pegas un buen trago de agua.\n");
    say(CAP(TNAME) + " bebe agua del barril.\n", TP);

    TP->SetDrink(TP->QueryDrink() +5);
    b_vacio++;
    return 1;
}


public void init()
{
    ::init();
    add_action("cmd_beber","beber");
}


public void create()
{
    ::create();

    SetShort("un barril");
    SetLong("Es un simple barril de madera que está aquí colocado para que "
            "los reclutas puedan beber durante su entrenamiento.\n");
    SetIds(({"barril"}));
    SetNoGet(1);
}

public void reset()
{
    //::reset();					// /std/thing no tiene reset
    b_vacio = 0;
}
