/****************************************************************************
Fichero: camino30.c
Autor: Ratwor
Fecha: 12/11/2006
Descripción: El nuevo camino Gorat-Ishtria
****************************************************************************/

#include "./path.h"
inherit CAMINOS "/simauria-gorat/camino_base";
create()
{
   ::create();
    SetIntLong(QueryIntLong()+
    " A lo lejos, hacia el oeste, se puede ver parte del faro de Gorat, mientras que "
    "al sur se aprecian las construcciones de sus viviendas.\n Hacia el este te dirijes "
    "a la región de Marhalt, pero al suroeste entrarías en el pequeño pueblo pesquero.\n");

    AddDetail(({"gorat", "Gorat"}), "Es el pueblo pesquero que se encuentra en la "
        "costa oeste de Simauria.\n");
    AddDetail("faro", "Es el faro de gorat que se levanta en la costa, ya lo tienes ahí "
        "mismo a lo lejos en el oeste.\n");
    AddDetail(({"construcciones", "construcción", "construccion"}), "Son las casas del "
        "pequeño pueblo pesquero de Gorat.\n");

    AddExit("este", "./camino29");
    AddExit("suroeste",BETWA "gorat/calles/callec2");
    AddItem(PNJ("camino/viajero"),REFRESH_DESTRUCT, d2());
}
