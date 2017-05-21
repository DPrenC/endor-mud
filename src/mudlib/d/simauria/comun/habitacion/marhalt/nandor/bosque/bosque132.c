/****************************************************************************
Fichero: bosque132.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque125");
    AddExit("oeste","./bosque131");
    AddExit("suroeste","./bosque137");
    AddExit("este","./bosque133");

}


