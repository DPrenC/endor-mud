/****************************************************************************
Fichero: bosque110.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("nordeste","./bosque107");
    AddExit("este","./bosque111");
    AddExit("suroeste","./bosque116");
    AddExit("sur","./bosque117");

}


