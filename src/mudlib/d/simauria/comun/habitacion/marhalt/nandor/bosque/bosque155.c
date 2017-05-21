/****************************************************************************
Fichero: bosque155.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("oeste","./bosque154");
    AddExit("este","./bosque156");
    AddExit("noroeste", "./bosque146");
    AddExit("norte", "./bosque147");
    AddExit("nordeste", "./bosque148");

}


