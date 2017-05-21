/****************************************************************************
Fichero: ungrim_08.c
Autor: Riberales
		[T] Tagoras
Creaci�n: 28/09/2005
Descripci�n: Un tramo de la calle Ungrim.
[T] 11/03/2009: A�ado puertas.
****************************************************************************/

#include "./path.h"
#include <door.h>
#include <properties.h>
#include <materials.h>
#include <scheduler.h>

inherit BASE_CIUDAD_ANNUFAM;

public void create()
{
    ::create();

    SetIntShort("el extremo oeste de la calle Ungrim");
    SetIntLong("Has llegado al extremo occidental de la calle Ungrim. Al "
               "norte se encuentra la entrada a la herrer�a de la ciudad, "
               "especializada en armas y armaduras para el Centro de "
               "Adiestramiento de Guerreros Enanos. Al oeste ves la muralla "
               "que recinta la ciudad y al este la continuaci�n de la calle "
               "en la que te encuentras.\n");
    AddLuzAntorchas();
    AddSuelo();

    AddDetail(({"muralla","murallas"}),
              "Son unas murallas de piedra, de casi tres metros de altura. "
              "Preservan a la ciudad de cualquier intento de intrusi�n.\n");

    AddDetail(({"herreria","herrer�a","pared norte"}),
              "Se trata de la herrer�a de Annufam, que a parte de fabricar "
              "armas y protecciones para el pueblo, se encarga de abastecer "
              "al Centro de Adiestramiento.\n");

    AddExit("norte",HAB_HERRERIA_ANNUFAM("herreria_01"));
    AddExit("este",HAB_UNGRIM_ANNUFAM("ungrim_07"));
    AddDoor("norte", "la puerta de la herrer�a", "Se trata de una gran puerta de madera maciza.\n",
        ({"puerta", "puerta maciza", "puerta de madera"}), GENDER_FEMALE,
        ([P_MATERIAL : M_MADERA, P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
}
