/****************************************************************************
Fichero: bosque144.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque137");
    AddExit("oeste","./bosque143");
    AddExit("sur","./bosque151");
    AddExit("sudeste","./bosque152");

}


