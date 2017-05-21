/****************************************************************************
Fichero: bosque060.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque055");
    AddExit("nordeste","./bosque056");
    AddExit("oeste","./bosque059");
    AddExit("este","./bosque061");
    AddExit("suroeste","./bosque066");

}


