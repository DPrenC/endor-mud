/****************************************************************************
Fichero: bosque142.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("nordeste","./bosque137");
    AddExit("este","./bosque143");
    AddExit("suroeste","./bosque149");
    AddExit("sur","./bosque150");
    AddExit("noroeste", CNS("cam32"));

}


