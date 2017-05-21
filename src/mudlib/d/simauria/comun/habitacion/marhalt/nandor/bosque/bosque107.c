/****************************************************************************
Fichero: bosque107.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque102");
    AddExit("norte","./bosque103");
    AddExit("nordeste","./bosque104");
    AddExit("suroeste","./bosque110");
    AddExit("sur","./bosque111");

}


