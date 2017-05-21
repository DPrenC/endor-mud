/****************************************************************************
Fichero: bosque147.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("nordeste","./bosque141");
    AddExit("oeste","./bosque146");
    AddExit("este","./bosque148");
    AddExit("suroeste","./bosque154");
    AddExit("sur","./bosque155");
    AddExit("sudeste","./bosque156");

}


