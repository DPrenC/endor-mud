/****************************************************************************
Fichero: bosque084.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("este","./bosque085");
    AddExit("noroeste", CNS("cam18"));
    AddExit("oeste", CNS("cam19"));
    AddExit("sur", CNS("cam20"));
    AddExit("sudeste", CNS("cam21"));

}


