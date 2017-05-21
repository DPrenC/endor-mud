/****************************************************************************
Fichero: pasillo1.c
Autor: Riberales
Fecha: 14/02/2006 23:14#include "./path
Descripci�n: Pasillo del gremio, remodelado.
Nota: Como en el vest�bulo, no ten�a ni fecha.
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
    SetIntShort("un pasillo del gremio de las Kisalas");
    SetIntLong("Te encuentras en un pasillo de piedra, iluminado por espirales"
               " fosforescentes que est�n colgadas por las paredes. Todo el "
               "techo tiene multitud de sellos con el s�mbolo de las Kisalas. "
               "Al Oeste llegar�s al vest�bulo del Gremio, al Este sigue el "
               "pasillo y al Norte est� la tienda de adopci�n de mascotas.\n");


    AddExit("este",AM_PASILLO("pasillo2"));
    AddExit("oeste",AM_VESTIBULO("vest5"));
    AddExit("norte",AM_VARIOS("tienda_mascotas"));
    AddDoor("norte", "la puerta de la tienda de mascotas",
        "Es la puerta de la tienda donde las amazonas adoptan sus mascotas. Est� hecha de "
            "madera con un panel de cristal en la parte superior.\n",
        ({"puerta","puerta de tienda","puerta norte"}),GENERO_FEMENINO,
        ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
        P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
        P_DOOR_TRANSPARENCY:1,P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));
}

