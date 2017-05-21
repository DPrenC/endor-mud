/*

    Nombre      : calle12
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Calle de la empalizada

*/
#include "./path.h"
inherit SIM_ROOM;

create() {
    ::create();

    SetLocate("Poblado de Enalel");
    SetIntShort("la calle de la empalizada");
    SetIntLong("Estás en la calle de la empalizada. Un gran edificio, situado "
    "al norte, parece ser la vivienda de la familia Rasquentar. Un pequeño puente "
    "situado al oeste da entrada a la casa de la familia Silves. La posada de la "
    "manzana feliz tiene su parte trasera  en la pared del sur. La calle de la empalizada "
    "transcurre hacia el nordeste.\n");
    SetIndoors(0);
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddDetail("suelo","El suelo de arena está lleno de pisadas de los transeuntes.\n");
    AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible "
    "distinguir un rastro.\n");
    AddDetail("empalizada","Es una empalizada de madera que rodea todo el poblado.\n");
    AddDetail(({"posada","manzana feliz","posada la manzana feliz"}),"Es un edificio "
    "de madera de cuyo interior se desprenden aromas de suculentas comidas.\n");
    AddExit("norte",ENALHAB"poblado/casas/rasquentars/hall");
    AddExit("nordeste",ENALHAB"poblado/calles/calle11");
    AddExit("oeste",ENALHAB"poblado/casas/silves/hall");
}
