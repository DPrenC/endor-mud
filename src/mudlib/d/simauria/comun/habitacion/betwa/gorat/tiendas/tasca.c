/****************************************************************************
Fichero: tasca.c
Autor: Ratwor
Fecha: 15/08/2006
Descripción: Nueva tasca para Gorat, cambiando el anterior archivo que era una copia exacta a la posada de nandor.
****************************************************************************/

#include "./path.h"
#include <properties.h>
#include <door.h>
#include <nightday.h>

inherit PUB;

create()
{
    ::create();
    SetIntShort("la tasca de Gorat");
    SetLocate("Gorat");
    SetIntLong(" Es el típico lugar de reunión en un pueblo pesquero y pequeño como "
	"gorat.\n  En la pared norte está el mostrador donde suele estar la tabernera, y "
	"detrás de él se encuentra la cocina.\n  Cerca de la puerta puedes ver un gran tonel "
	"y, repartidas por la estancia, un pequeño número de mesas y sillas, la mayoría "
	"ocupadas por distintos comensales.\n");

    AddDetail(({"tonel", "barril"}), "Un gran tonel que supones que contiene vino, ahí "
    "lo menos le caben 500 litros.\n");
    AddDetail(({"mesas", "sillas"}), "Casi una decena de mesas con sus respectivas "
    "sillas se encuentran repartidas por el local.\n");
    AddDetail(({"mostrador", "barra"}), "Un mostrador de varios metros ocupa toda la "
    "pared norte de la tasca, detrás se encuentra la cocina.\n");
    AddDetail(({"gente", "ciudadanos", "comensales", "clientes", "funcionarios"}),
    "Comen y charlan animádamente.\n");

    SetIntBright(45);
    SetIntNoise("El sonido de risas y voces es muy fuerte.\n");
    SetIntSmell("Un olor a comida sale de la cocina.\n");
    AddExit("sur", BETWA "/gorat/calles/callep5");
    AddDoor("sur", "la puerta de la calle",
    "Es la puerta de salida a la calle, de madera y sin adornos.\n",
    ({"puerta", "puerta de madera", "puerta de salida", "puerta de la calle"}),
    ([P_DOOR_CLOSE_TIME : ({ND_NIGHT, ND_PREDAWN, ND_DAWN})]));
    AddItem(GORPNJ("jerton"), REFRESH_DESTRUCT);
    SetKeeper(GORPNJ("tabernera_gorat"));
    SetNotifyExits("sur");
    SetLastDest("../calles/callep5");
    SetCloseTime(({ND_NIGHT, ND_PREDAWN, ND_DAWN}));

    AddFood("sepia a la plancha","un plato de",7,10,0, "La tabernera te sirve la sepia.\n");
    AddFood("sopa de merluza","un plato de",6,12,0, "La tabernera te sirve la sopa "
           "caliente.\n");
    AddFood("sopa de lubina","un plato de",7,11,0, "La tabernera te trae la sopa en su "
           "punto.\n");
    AddFood("gambas","un plato de",7,10,0, "Te comes las gambas sin cabeza, ¡Para "
           "chuparse los dedos!.\n");
    AddFood("pescaditos fritos","un plato de",7,10,0, "Te comes sin prisa los pescaditos,"
           " están crugientes.\n");
    AddFood("ensalada especial","una fuente de",3,6,0,"La verdad es que no incha mucho,"
           " parece que estés a dieta.\n");
    AddFood("consomé de pescado","un tazón de",5,7,0, "Te tomas el consomé, está sabroso "
           "y alimenta.\n");
    AddDrink("grog","una jarra de",2,10,5,0, "La verdad es que lo has provado mejores.\n");
    AddDrink("ron","un vaso de",4,12,6,0, "Te bebes el ron sin respirar, ¡Qué fuerte "
           "está este ron!.\n");
    AddDrink("vino tinto","un vaso de",3,9,9,0, "La tabernera te trae el vino, está algo "
           "picado, pero te lo bebes igual.\n");
    AddDrink("cerveza","una jarra de",4,5,10,0, "Está fresquita y sienta muy bien.\n");
    AddDrink("agua","un vaso de",2,0,12,0,"Te bebes el agua de un trago, te sienta "
    "estupendamente.\n");
}
