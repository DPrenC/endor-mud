/****************************************************************************
Fichero: bosque131.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque125");
    AddExit("este","./bosque132");
    AddExit("sur","./bosque137");
    AddExit("noroeste", CNS("cam29"));
}


