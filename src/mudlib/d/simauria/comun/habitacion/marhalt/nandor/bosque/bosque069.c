/****************************************************************************
Fichero: bosque069.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("nordeste","./bosque065");
    AddExit("este","./bosque070");
    AddExit("noroeste", CNS("cam16"));
    AddExit("oeste", CNS("cam17"));
    AddExit("suroeste", CNS("cam18"));

}


