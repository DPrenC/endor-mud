/****************************************************************************
Fichero: bosque143.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque137");
    AddExit("oeste","./bosque142");
    AddExit("este","./bosque144");
    AddExit("suroeste","./bosque150");
    AddExit("sudeste","./bosque151");

}


