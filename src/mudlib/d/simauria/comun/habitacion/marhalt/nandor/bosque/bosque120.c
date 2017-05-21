/****************************************************************************
Fichero: bosque120.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque113");
    AddExit("oeste","./bosque119");
    AddExit("suroeste","./bosque124");

}


