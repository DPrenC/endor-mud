/****************************************************************************
Fichero: bosque057.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("este","./bosque058");
    AddExit("noroeste","./bosque053");
    AddExit("suroeste","./bosque063");
    AddExit("sur","./bosque064");

}


