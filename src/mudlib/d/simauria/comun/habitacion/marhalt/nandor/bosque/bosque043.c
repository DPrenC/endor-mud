/****************************************************************************
Fichero: bosque043.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque039");
    AddExit("sur","./bosque050");
    AddExit("este","./bosque044");
    AddExit("oeste",CNS("cam10"));
    AddExit("noroeste", CNS("cam09"));
}


