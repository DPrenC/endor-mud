/*

    Nombre      : calle16
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Calle de las cosechas

*/
#include "./path.h"
inherit SIM_ROOM;

create() {
    ::create();

    SetLocate("Poblado de Enalel");
    SetIntShort("la calle de las cosechas");
    SetIntLong("Estás en medio de la calle de las cosechas. Las estatuillas y "
    "postes conmemorativos parecen ocupar gran parte de la calle aquí. La casa de "
    "la familia Benjus se encuentra hacia el norte. La calle de las cosechas "
    "transcurre de este a oeste.\n");
    SetIndoors(0);
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddDetail("suelo","El suelo de arena está lleno de pisadas de los transeuntes.\n");
    AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible "
    "distinguir un rastro.\n");
    AddDetail(({"postes","poste","estatuillas","estatuilla"}),"Son los símbolos "
    "que recuerdan algunas cosechas de gran calidad o hazañas de algunos héroes locales.\n");
    AddExit("este",ENALHAB"poblado/calles/calle15");
    AddExit("oeste",ENALHAB"poblado/calles/calle17");
    AddExit("norte",ENALHAB"poblado/casas/benjus/hall");
    AddDoor("norte", "la puerta de la casa",
    "Es la puerta de la casa de la familia Benjus.\n",
    ({"puerta", "puerta del norte", "puerta de la casa"}));
}
