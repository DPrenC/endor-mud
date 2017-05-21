/****************************************************************************
Fichero: bosque117.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque110");
    AddExit("nordeste","./bosque111");
    AddExit("oeste","./bosque116");
    AddExit("suroeste","./bosque122");
    AddExit("sudeste", "./zona_guardabosques");
}


