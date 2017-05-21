/****************************************************************************
Fichero: camino30.c
Autor: Ratwor
Fecha: 12/11/2006
Descripci�n: El nuevo camino Gorat-Ishtria
****************************************************************************/

#include "./path.h"
inherit CAMINOS "/simauria-gorat/camino_base";
create()
{
   ::create();
    SetIntLong(QueryIntLong()+
    " A lo lejos, hacia el oeste, se puede ver parte del faro de Gorat, mientras que "
    "al sur se aprecian las construcciones de sus viviendas.\n Hacia el este te dirijes "
    "a la regi�n de Marhalt, pero al suroeste entrar�as en el peque�o pueblo pesquero.\n");

    AddDetail(({"gorat", "Gorat"}), "Es el pueblo pesquero que se encuentra en la "
        "costa oeste de Simauria.\n");
    AddDetail("faro", "Es el faro de gorat que se levanta en la costa, ya lo tienes ah� "
        "mismo a lo lejos en el oeste.\n");
    AddDetail(({"construcciones", "construcci�n", "construccion"}), "Son las casas del "
        "peque�o pueblo pesquero de Gorat.\n");

    AddExit("este", "./camino29");
    AddExit("suroeste",BETWA "gorat/calles/callec2");
    AddItem(PNJ("camino/viajero"),REFRESH_DESTRUCT, d2());
}
