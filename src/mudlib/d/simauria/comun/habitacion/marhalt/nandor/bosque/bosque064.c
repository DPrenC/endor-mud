/****************************************************************************
Fichero: bosque064.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque057");
    AddExit("nordeste","./bosque058");
    AddExit("oeste","./bosque063");
    AddExit("sudeste","./bosque068");

}


