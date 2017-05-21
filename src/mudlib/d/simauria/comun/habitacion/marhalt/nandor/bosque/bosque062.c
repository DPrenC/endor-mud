/****************************************************************************
Fichero: bosque062.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque056");
    AddExit("oeste","./bosque061");
    AddExit("este","./bosque063");
    AddExit("sur","./bosque067");

}


