/****************************************************************************
Fichero: bosque149.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("nordeste","./bosque142");
    AddExit("este","./bosque150");
    AddExit("sudeste","./bosque157");
    AddExit("noroeste", CNS("cam34"));
    AddExit("oeste", CNS("cam35"));
    AddExit("suroeste", CNS("cam36"));

}


