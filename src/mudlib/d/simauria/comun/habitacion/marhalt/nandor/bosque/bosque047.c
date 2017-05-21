/****************************************************************************
Fichero: bosque047.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("este","./bosque048");
    AddExit("sur","./bosque053");
    AddExit("suroeste", "./bosque052");
    AddExit("nordeste", "./bosque041");

}


