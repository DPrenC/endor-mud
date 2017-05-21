/*
DESCRIPCION  : patio
FICHERO      : patio15.c
MODIFICACION : 16-07-00 [Maler] Creacion
*/

#include "path.h"
#include <properties.h>
#include <door.h>
#include <materials.h>
#include <sounds.h>
#include <scheduler.h>

inherit ROOMFF("fortalez");
create()
{
    ::create();
    SetIntShort("un patio");
    SetIntLong("Est�s en un patio dentro de la fortaleza. Antiguamente, esta parte del "
    "castillo se usaba para el adiestramiento de la tropa. Ahora ya no es m�s que "
    "un lugar de tr�nsito dentro del recinto.\n  Del oeste te llega el agradable olor a "
    "comida, y del este el estr�pito incesante del metal chocando contra metal.\n");
    AddExit("norte",ROOMFF("lord"));
    AddExit("este",ROOMFF("herreria"));
    AddExit("sur",ROOMFF("patio06"));
    AddExit("oeste",ROOMFF("pub2"));
    AddDoor("norte", "un gran port�n",
        "Es una enorme puerta de madera que da paso al sal�n del trono.\n",
        ({"puerta", "porton", "port�n", "gran puerta", "puerta del norte"}), GENDER_MALE,
        ([P_DOOR_CLOSE_SOUND: SND_SUCESOS("cerrar_porton"),
        P_DOOR_OPEN_SOUND: SND_SUCESOS("abrir_porton")]));
    AddDoor("oeste", "la puerta del mes�n",
    "Es la puerta para entrar al mes�n.\n",
    ({"puerta", "puerta del oeste", "puerta del meson", "puerta del mes�n"}));
    AddDoor("este", "la puerta de la herrer�a", "Es una vieja puerta medio rota.\n",
    ({"puerta", "puerta vieja", "puerta de la herrer�a", "puerta del este"}),
    ([P_DOOR_CLOSE_TIME : S_CLOSED_AT_NIGHT]));
    AnyadirPnjs();
  }
