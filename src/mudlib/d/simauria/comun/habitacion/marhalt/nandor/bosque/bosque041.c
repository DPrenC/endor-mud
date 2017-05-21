/****************************************************************************
Fichero: bosque041.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("este","./bosque042");
    AddExit("sur","./bosque048");
    AddExit("noroeste","./bosque037");
    AddExit("nordeste","./bosque038");
    AddExit("suroeste","./bosque047");
    AddExit("sudeste", "./zona_lenyador");
}


