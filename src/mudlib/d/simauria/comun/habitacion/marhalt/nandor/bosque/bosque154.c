/****************************************************************************
Fichero: bosque154.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("este","./bosque155");
    AddExit("suroeste","./bosque160");
    AddExit("noroeste","./bosque145");
    AddExit("norte","./bosque146");
    AddExit("nordeste","./bosque147");

}


