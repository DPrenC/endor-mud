/****************************************************************************
Fichero: bosque111.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque107");
    AddExit("oeste","./bosque110");
    AddExit("este","./bosque112");
    AddExit("suroeste","./bosque117");
    AddExit("sudeste", "./bosque118");
}


