/****************************************************************************
Fichero: bosque090.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque085");
    AddExit("nordeste","./bosque086");
    AddExit("sur", "./bosque094");
    AddExit("sudeste", "./bosque095");
    AddExit("oeste", CNS("cam21"));
    AddExit("suroeste", CNS("cam22"));

}


