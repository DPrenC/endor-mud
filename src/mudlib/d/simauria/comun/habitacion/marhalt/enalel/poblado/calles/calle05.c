/*

    Nombre      : calle05
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Calle del comercio

*/
#include "./path.h"
inherit STAGECOACH_STOP;
create() {
    ::create();

    SetLocate("Poblado de Enalel");
    SetClimateServer(SERVER);
    SetIntShort("la calle del comercio, en una parada de diligencias");
    SetIntLong("Estás en la calle del comercio. En esta parte de la calle el "
    "comercio ha dejado lugar para la edificación del cuartel de la guardia, situado "
    "al norte, y a la mansión de la familia Prialane, grandes comerciantes humanos, "
    "situada al sur.\n Por la importancia de este trozo de calle, se ha hubicado aquí "
    "la parada de la diligencia Porhalt, que une Enalel con la villa de Nandor "
    "por el camino del norte de Marhalt.\n La calle discurre de este a oeste.\n");
    SetIndoors(0);
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddDetail("suelo","El suelo de arena está lleno de pisadas de los transeuntes.\n");
    AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible "
    "distinguir un rastro.\n");
    AddDiligencia(PORHALT("porhalt"));
    SetNombreParada("enalel");
    AddExit("este",ENALHAB"poblado/calles/calle04");
    AddExit("oeste",ENALHAB"poblado/calles/calle06");
    AddExit("norte",ENALHAB"poblado/varios/cuartel");
    AddExit("sur",ENALHAB"poblado/casas/prialanes/hall");
    AddDoor("norte",  "la puerta del cuartel",
    "Es la puerta principal para entrar al cuartel de la guardia de Enalel.\n",
    ({"puerta", "puerta del cuartel", "puerta principal del cuartel", "puerta del norte"}));
    AddDoor("sur", "la puerta de la casa",
    "Es la puerta de entrada a la vivienda de la familia Prialane.\n",
    ({"puerta", "puerta de la casa", "puerta del sur"}));
    SetKeeper(PNJ("diligencia/taquillero"));
}