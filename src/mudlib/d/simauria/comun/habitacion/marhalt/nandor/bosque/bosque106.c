/****************************************************************************
Fichero: bosque106.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque101");
    AddExit("oeste","./bosque105");
    AddExit("sur","./bosque109");

}


