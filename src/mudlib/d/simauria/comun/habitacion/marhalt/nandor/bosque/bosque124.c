/****************************************************************************
Fichero: bosque124.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque118");
    AddExit("norte","./bosque119");
    AddExit("nordeste","./bosque120");
    AddExit("oeste","./bosque123");
    AddExit("suroeste","./bosque129");
    AddExit("sur","./bosque130");

}


