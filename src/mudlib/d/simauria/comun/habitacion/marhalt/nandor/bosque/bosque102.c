/****************************************************************************
Fichero: bosque102.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque097");
    AddExit("norte","./bosque098");
    AddExit("este","./bosque103");
    AddExit("sudeste","./bosque107");

}


