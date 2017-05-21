/****************************************************************************
Fichero: bosque040.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque034");
    AddExit("sur","./bosque045");
    AddExit("sudeste","./bosque046");
    AddExit("nordeste", "./bosque035");
    AddExit("suroeste", "./bosque044");
}


