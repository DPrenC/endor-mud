/****************************************************************************
Fichero: pasillo2.c
Autor: Riberales
Fecha: 14/02/2006
Descripción: Pasillo del gremio, remodelado del todo.
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
    SetIntShort("un pasillo del Gremio de las Kisalas");

    SetIntLong("Te encuentras en un largo pasillo formado por un túnel de "
               "piedra en cuyas paredes hay muchas espirales fosforescentes "
               "que iluminan la estancia. Por el techo y el suelo están "
               "tallados numerosos sellos que representan el símbolo de las "
               "Kisalas. Al oeste sigue el pasillo, y al sur está la Arena, "
               "lugar de entrenamiento para las Kisalas.\n");


    AddExit("oeste",AM_PASILLO("pasillo1"));
    AddExit("sur",AM_ARENA("arena1"));
    AddExit("norte",AM_VARIOS("magia"));
    AddDoor("norte", "la puerta de la tienda de magia",
        "Es la puerta de la tienda de magia. Está hecha de madera con un panel de cristal en "
            "la parte superior.\n",
        ({"puerta","puerta de tienda","puerta norte"}),GENERO_FEMENINO,
        ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
        P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
        P_DOOR_TRANSPARENCY:1,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));
}

