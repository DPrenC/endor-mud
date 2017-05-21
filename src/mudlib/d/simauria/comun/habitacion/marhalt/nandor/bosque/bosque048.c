/****************************************************************************
Fichero: bosque048.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("oeste","./bosque047");
    AddExit("norte","./bosque041");
    AddExit("nordeste", "./bosque042");
    AddExit("suroeste", "./bosque053");
    AddExit("este", "./zona_lenyador");
}


