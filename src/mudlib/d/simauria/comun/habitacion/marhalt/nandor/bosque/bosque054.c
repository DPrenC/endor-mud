/****************************************************************************
Fichero: bosque054.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("este","./bosque055");
    AddExit("norte","./bosque050");
    AddExit("noroeste","./bosque049");
    AddExit("sudeste","./bosque059");

}


