/****************************************************************************
Fichero: bosque046.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("oeste","./bosque045");
    AddExit("noroeste","./bosque040");
    AddExit("sur","./bosque051");
    AddExit("sudeste","./bosque052");
}


