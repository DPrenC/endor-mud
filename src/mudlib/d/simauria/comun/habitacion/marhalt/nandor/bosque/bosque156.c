/****************************************************************************
Fichero: bosque156.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque147");
    AddExit("norte","./bosque148");
    AddExit("oeste", "./bosque155");
}


