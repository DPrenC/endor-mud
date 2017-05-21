/****************************************************************************
Fichero: bosque039.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("sur","./bosque043");
    AddExit("sudeste", "./bosque044");
    AddExit("noroeste",CNS("cam08"));
    AddExit("oeste",CNS("cam09"));
    AddExit("suroeste",CNS("cam10"));
}


