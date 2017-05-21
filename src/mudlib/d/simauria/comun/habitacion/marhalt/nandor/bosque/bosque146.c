/****************************************************************************
Fichero: bosque146.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque140");
    AddExit("oeste","./bosque145");
    AddExit("este","./bosque147");
    AddExit("sur","./bosque154");
    AddExit("sudeste","./bosque155");

}


