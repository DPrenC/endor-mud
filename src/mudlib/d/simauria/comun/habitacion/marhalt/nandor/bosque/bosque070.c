/****************************************************************************
Fichero: bosque070.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque065");
    AddExit("oeste","./bosque069");
    AddExit("este", "./bosque071");

}


