/****************************************************************************
Fichero: ojo_orco.c
Autor: Riberales
Creación: 22/08/2005
Descripción: otra de las tabernas de Annufam
****************************************************************************/

#include "./path.h"
#include <keeper.h>

inherit PUB;
inherit KEEPER;

public void create()
{
    ::create();

    SetIntShort("la taberna Ojo de Orco");
    SetLocate("annufam");
    SetIntLong(W("Has entrado a una de las dos posadas de la ciudad. En este "
                 "caso, a Ojo de Orco. Con ese nombre, no quieres ni pensar "
                 "lo que pondrán de comer. Ves algunas mesas dispersas por la "
                 "habitación, y una barra con un menú al lado.\n"));


    AddDetail("barra",W("Es una típica barra de bar o taberna. Hay varias "
                        "jarras vacías sobre ella. Al final de la misma "
                        "observas un menú que puedes leer para pedir lo que te"
                        " apetezca.\n"));


    AddDetail(({"mesa","mesas","sillas","silla"}),
              W("Son varias mesas de cuatro personas, con sus respectivas "
                "sillas para que los enanos puedan reunirse y charlar mientras"
                " beben y comen.\n"));


    SetKeeper(PNJ_CIUDAD_ANNUFAM("doignus"));
    SetIndoors(1);
    SetIntLight(45);
    SetIntNoise("Escuchas el ruido típico de una taberna.\n");
    SetIntSmell("Un peculiar olor sale de detrás de la barra.\n");
    AddExit("norte",HAB_UNGRIM_ANNUFAM("ungrim_03"));


    //Ahora el menú.

    AddFood("chuletas de cordero","media docena de",10,11,0);
    AddFood("sopa ojo de orco","un plato de",15,18,0);
    AddDrink("cerveza","Una fresca jarra de",7,5,5,0);
    AddDrink("vino","un chato de",5,4,4,0);
    AddDrink("agua","un vaso de",3,0,8,0);
}

// para pedir.
int _porder(string str)
{
    //if (CantAttend(NOTIFY_FAIL)) return 0;
    if (CantAttend(K_NOTIFY)) return 0;
    return ::_porder(str);
}
