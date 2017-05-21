/****************************************************************************
Fichero: bosque137.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque131");
    AddExit("nordeste","./bosque132");
    AddExit("suroeste","./bosque142");
    AddExit("sur","./bosque143");
    AddExit("sudeste","./bosque144");

}


