/****************************************************************************
Fichero: bosque095.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque090");
    AddExit("oeste","./bosque094");
    AddExit("este", "./bosque096");
    AddExit("sudeste", "./bosque101");
    AddExit("suroeste", CNS("cam23"));

}


