/****************************************************************************
Fichero: bosque056.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque051");
    AddExit("suroeste","./bosque060");
    AddExit("sur","./bosque061");
    AddExit("sudeste","./bosque062");

}


