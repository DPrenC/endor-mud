/****************************************************************************
Fichero: callec1.c
Autor: Ratwor
Fecha: 03/04/2008
Descripción: la calle del pescador, con la parada de la diligencia zepar.
****************************************************************************/

#include "./path.h"
inherit  STAGECOACH_STOP;
create () {
    ::create();
    SetLocate("Gorat");
    SetClimateServer(SERVER);
    SetIntShort("la calle del pescador, en una parada de diligencias");
    SetIntLong("estás en la pequeña calle del pescador que une el camino de entrada al "
    "pueblo hacia el nordeste, con la calle principal de Gorat hacia el sur.\n"
    "En este mismo trozo de calle es donde se encuentra una de las paradas de las "
    "diligencias que hacen su trayecto en el dominio de Simauria.\n");
    SetIndoors(0);
    AddDiligencia(ZEPAR("zepar"));
    SetNombreParada("gorat");
    SetKeeper(PNJ("diligencia/taquillero"));
    AddExit("nordeste", "./callec2");
    AddExit("sur","./callep2");

}
