/****************************************************************************
Fichero: cam36.c
Autor: Ratwor
Fecha: 19/09/2007
Descripción: La parada de diligencias de Ishtria.
****************************************************************************/

#include "./path.h"
inherit STAGECOACH_STOP;

create() {
    ::create();
    SetIntShort("una parada de diligencias");
    SetIntLong("Estás en una de las paradas de diligencias que hay por toda Simauria. "
  	    "Aquí puedes ver que paran la diligencia Zepar, que hace el recorrido Nandor-"
  	    "Gorat-Ishtria y la Rhoek, que hace el Ishtria-Koek.\n Puedes ver un poste "
  	    "con un cartel colgado.\n");
  	SetClimateServer(SERVER);
    AddDiligencia(ZEPAR("zepar"));
    AddDiligencia(RHOEK("rhoek"));
    SetNombreParada("Ishtria");
    SetKeeper(PNJ("diligencia/taquillero"));
    AddExit("sur","./cam37");
    AddExit("norte","./cam35");
    AddExit("nordeste", MARH("nandor/bosque/bosque149"));
    HideExit("nordeste",1);
    AddItem(PNJ("camino/viajero"),REFRESH_DESTRUCT, d2());
}

