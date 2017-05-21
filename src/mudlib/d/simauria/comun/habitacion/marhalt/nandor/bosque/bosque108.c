/****************************************************************************
Fichero: bosque108.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque104");
    AddExit("suroeste","./bosque112");
    AddExit("sudeste","./bosque113");

}


