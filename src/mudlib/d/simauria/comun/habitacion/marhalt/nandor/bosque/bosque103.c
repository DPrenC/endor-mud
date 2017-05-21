/****************************************************************************
Fichero: bosque103.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque098");
    AddExit("nordeste","./bosque099");
    AddExit("este","./bosque104");
    AddExit("oeste","./bosque102");
    AddExit("sur","./bosque107");

}


