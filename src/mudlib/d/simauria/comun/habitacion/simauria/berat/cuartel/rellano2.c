/****************************************************************************
Fichero: rellano2.c
Autor: Dharkus
Fecha: 27/04/2010
Descripción: Un rellano en el cuartel de Berat
****************************************************************************/


#include "./path.h"
#include <properties.h>
inherit ROOM;

create()
{
    ::create();
    SetLocate("Berat");
    SetIntShort("un rellano en el cuartel de Berat");
    SetIntLong("Es un rellano que contiene las escaleras para bajar al piso inferior.\n "
    "Al oeste está la puerta que conduce al despacho del capitán de la guardia, "
    "y al este la sala de descanso.\n");
    AddDetail("escaleras","Son unas escaleras de madera que bajan a la planta inferior "
    "del cuartel.\n");
    SetIntNoise("Escuchas el sonido de los guardias deambulando por el edificio.\n");
    SetIntBright(20);
    AddExit("este", "./descanso");
    AddExit("oeste", "./despacho");
    AddExit("abajo", "./rellano1");
    AddDoor("oeste", "la puerta del despacho del capitán", "Es la puerta que separa "
    "el rellano con el despacho del capitán.\n", ({"puerta del despacho",
    "puerta oeste", "puerta del oeste", "puerta"}));
    AddDoor("este", "la puerta de la sala de descanso", "Es la puerta que separa "
    "el rellano con la sala de descanso.\n", ({"puerta de la sala de descanso", 
    "puerta este", "puerta del este", "puerta"}));
}
