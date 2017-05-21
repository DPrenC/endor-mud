/****************************************************************************
Fichero: bosque138.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque133");
    AddExit("norte","./bosque134");
    AddExit("este","./bosque139");

}


