/****************************************************************************
Fichero: vest1.c
Autor: Riberales
Fecha: 14/02/2006
Descripción: Vestíbulo de las Kisalas. Remodelación espacial total.
Notas: [R] No tiene ni fecha, así es que le pongo la actual.
****************************************************************************/


#include "path.h"
#include <properties.h>
#include <door.h>
#include <sounds.h>
#include <scheduler.h>
inherit INTERIOR_BASE;

create()
{
    ::create();
    SetIntShort("el vestíbulo del gremio de las Kisalas");
    SetIntLong("Te encuentras en una parte del amplio vestíbulo de las "
               "Kisalas. En él, todas las paredes tienen grabados que "
               "representan diversas historias de la Órden, al igual que el "
               "código por el cual se rigen. En el suelo destaca un enorme "
               "sello que representa el símbolo de las Kisalas. Hacia el "
               "norte y el nordeste el vestíbulo sigue, al Este está la "
               "entrada, y al oeste la taberna del gremio.\n");

    AddDetalleGrabados();
    AddDetalleRelieves();

    AddExit("este",AM_ROOM("entrada"));
    AddExit("nordeste",AM_VESTIBULO("vest4"));
    AddExit("norte",AM_VESTIBULO("vest3"));
    AddExit("oeste",AM_VARIOS("taberna"));
    AddDoor("oeste", "la puerta de la taberna",
        "Es la puerta de la taberna del gremio. Está hecha de madera con un panel de cristal "
            "en la parte superior.\n",
        ({"puerta","puerta de taberna","puerta norte"}),GENERO_FEMENINO,
        ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
        P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
        P_DOOR_TRANSPARENCY:1,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));
}
