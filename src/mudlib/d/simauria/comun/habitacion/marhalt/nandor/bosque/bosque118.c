/****************************************************************************
Fichero: bosque118.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque111");
    AddExit("norte","./bosque112");
    AddExit("este","./bosque119");
    AddExit("sur","./bosque123");
    AddExit("sudeste","./bosque124");
    AddExit("suroeste", "./zona_guardabosques");
}


