/****************************************************************************
Fichero: bosque153.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("oeste","./bosque152");
    AddExit("suroeste","./bosque158");
    AddExit("sudeste","./bosque159");

}

