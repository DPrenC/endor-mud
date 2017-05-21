/****************************************************************************
Fichero: bosque077.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("sur","./bosque086");
    AddExit("norte","./bosque072");
    AddExit("noroeste", "./bosque071");
    AddExit("nordeste", "./bosque073");

}


