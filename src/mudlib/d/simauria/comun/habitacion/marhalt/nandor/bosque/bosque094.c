/****************************************************************************
Fichero: bosque094.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque090");
    AddExit("este","./bosque095");
    AddExit("noroeste", CNS("cam21"));
    AddExit("oeste", CNS("cam22"));
    AddExit("sur", CNS("cam23"));
}


