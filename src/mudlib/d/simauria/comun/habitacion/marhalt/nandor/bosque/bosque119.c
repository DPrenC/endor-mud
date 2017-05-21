/****************************************************************************
Fichero: bosque119.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque112");
    AddExit("nordeste","./bosque113");
    AddExit("oeste","./bosque118");
    AddExit("este","./bosque120");
    AddExit("suroeste","./bosque123");
    AddExit("sur","./bosque124");

}


