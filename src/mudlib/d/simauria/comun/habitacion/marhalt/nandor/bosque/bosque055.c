/****************************************************************************
Fichero: bosque055.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("oeste","./bosque054");
    AddExit("noroeste","./bosque050");
    AddExit("sur","./bosque059");
    AddExit("sudeste","./bosque060");

}


