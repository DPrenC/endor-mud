/****************************************************************************
Fichero: bosque139.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque134");
    AddExit("oeste","./bosque138");
    AddExit("este","./bosque140");
    AddExit("sudeste","./bosque145");
}


