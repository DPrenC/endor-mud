/****************************************************************************
Fichero: bosque145.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque139");
    AddExit("norte","./bosque140");
    AddExit("este","./bosque146");
    AddExit("sudeste","./bosque154");

}


