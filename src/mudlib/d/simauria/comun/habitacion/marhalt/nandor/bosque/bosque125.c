/****************************************************************************
Fichero: bosque125.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("nordeste","./bosque121");
    AddExit("sur","./bosque131");
    AddExit("sudeste","./bosque132");
    AddExit("noroeste", CNS("cam28"));
    AddExit("oeste", CNS("cam29"));

}


