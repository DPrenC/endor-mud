/*

    Nombre      : calle15
    Zona        : Poblado de Enalel
    Autor       : Tyflos
    Fecha       : 09/01/2005
    Descripción : Cruce de la calle de las cosechas

*/
#include "./path.h"
inherit SIM_ROOM;

create() {
    ::create();

    SetLocate("Poblado de Enalel");
    SetIntShort("un cruce entre calles");
    SetIntLong("Estás en un cruce de caminos que comunica la calle de las cosechas "
    "y la calle del manzanar. Multitud de postes y estatuillas rodean este camino. La "
    "casa de la familia gholves se levanta, majestuosa, hacia el norte. Hacia el oeste "
    "continúa la calle de las cosechas y hacia el suroeste comienza la calle del manzanar. "
    "Hacia el nordeste, la calle de las cosechas se une con la calle del comercio.\n");
    SetIntNoise("Los sonidos de la naturaleza inundan el lugar.\n");
    SetIntSmell("El aroma de las manzanas flota en el lugar.\n");
    AddDetail(({"suelo"}),"El suelo de arena está lleno de pisadas de los transeuntes.\n");
    AddDetail(({"pisada","pisadas"}),"Las pisadas van de un sitio a otro. Es imposible distinguir un rastro.\n");
    AddDetail(({"postes","poste","estatuillas","estatuilla"}),"Son los símbolos que "
    "recuerdan algunas cosechas de gran calidad o hazañas de algunos héroes locales.\n");
    AddExit("nordeste",ENALHAB"poblado/calles/calle14");
    AddExit("oeste",ENALHAB"poblado/calles/calle16");
    AddExit("suroeste",ENALHAB"poblado/calles/calle19");
    AddExit("norte",ENALHAB"poblado/casas/gholves/hall");
  AddItem(ENALPNJ"otros/pueblerino",REFRESH_DESTRUCT,d2());
}