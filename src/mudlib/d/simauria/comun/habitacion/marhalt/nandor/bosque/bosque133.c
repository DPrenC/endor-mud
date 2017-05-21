/****************************************************************************
Fichero: bosque133.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("nordeste","./bosque126");
    AddExit("oeste","./bosque132");
    AddExit("este","./bosque134");
    AddExit("sudeste","./bosque138");

}


