/****************************************************************************
Fichero: bosque114.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("sudeste","./bosque121");
    AddExit("norte", CNS("cam25"));
    AddExit("noroeste", CNS("cam26"));
    AddExit("oeste", CNS("cam27"));
    AddExit("suroeste", CNS("cam28"));

}


