/****************************************************************************
Fichero: bosque085.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("oeste","./bosque084");
    AddExit("sudeste","./bosque090");
    AddExit("suroeste",CNS("cam20"));
    AddExit("sur", CNS("cam21"));

}


