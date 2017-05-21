/****************************************************************************
Fichero: bosque121.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque114");
    AddExit("nordeste","./bosque115");
    AddExit("suroeste","./bosque125");

}


