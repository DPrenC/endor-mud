/****************************************************************************
Fichero: pasillo3.c
Autor: Riberales
Fecha: 14/02/2006
Descripci�n: Pasillo del gremio de Kisalas, remodelaci�n integral.
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
    SetIntLong("Te encuentras en un pasillo de piedra, iluminado por espirales fosforescentes "
        "que est�n colgadas por las paredes. Todo el techo tiene multitud de sellos con el "
        "s�mbolo de las Kisalas. Al este puedes ver el vest�bulo del Gremio, y al norte se "
        "encuentra el banco de las Kisalas.\n");
    AddExit("norte",AM_VARIOS("banco"));
    AddExit("este",AM_VESTIBULO("vest3"));
    AddDoor("norte", "la puerta del banco",
        "Es la puerta que conduce al banco. Est� hecha de gruesos paneles de madera enmarcados "
            "por listones de hierro.\n",
        ({"puerta","puerta del banco","puerta norte"}),GENERO_FEMENINO,
        ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
        P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_puerta_campanillas"),
        P_DOOR_CLOSE_TIME:S_CLOSED_AT_NIGHT]));
}
