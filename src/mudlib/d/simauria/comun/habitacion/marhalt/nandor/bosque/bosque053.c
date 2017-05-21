/****************************************************************************
Fichero: bosque053.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque047");
    AddExit("oeste","./bosque052");
    AddExit("sudeste","./bosque057");
    AddExit("nordeste","./bosque048");

}


