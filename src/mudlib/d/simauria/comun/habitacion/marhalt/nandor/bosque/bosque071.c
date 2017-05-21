/****************************************************************************
Fichero: bosque071.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque065");
    AddExit("oeste","./bosque070");
    AddExit("este", "./bosque072");
    AddExit("sudeste", "./bosque077");

}


