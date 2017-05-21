/****************************************************************************
Fichero: bosque097.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque091");
    AddExit("este","./bosque098");
    AddExit("oeste", "./bosque096");
    AddExit("suroeste", "./bosque101");
    AddExit("sudeste", "./bosque102");

}


