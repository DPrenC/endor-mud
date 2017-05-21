/****************************************************************************
Fichero: bosque065.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("suroeste","./bosque069");
    AddExit("sur","./bosque070");
    AddExit("sudeste", "./bosque071");
    AddExit("norte", CNS("cam13"));
    AddExit("noroeste", CNS("cam14"));
}


