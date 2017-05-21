/****************************************************************************
Fichero: bosque049.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("este","./bosque050");
    AddExit("sudeste","./bosque054");
    AddExit("norte", CNS("cam10"));
    AddExit("oeste", CNS("cam11"));
    AddExit("suroeste", CNS("cam12"));

}


