/****************************************************************************
Fichero: bosque050.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque043");
    AddExit("oeste","./bosque049");
    AddExit("sur","./bosque054");
    AddExit("sudeste","./bosque055");
    AddExit("noroeste", CNS("cam10"));
}


