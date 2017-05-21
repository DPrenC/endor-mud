/****************************************************************************
Fichero: bosque140.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("oeste","./bosque139");
    AddExit("sur","./bosque145");
    AddExit("sudeste","./bosque146");

}


