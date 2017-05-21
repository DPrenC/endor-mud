/****************************************************************************
Fichero: bosque123.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque118");
    AddExit("nordeste","./bosque119");
    AddExit("este","./bosque124");
    AddExit("suroeste","./bosque128");
    AddExit("sur","./bosque129");
    AddExit("sudeste","./bosque130");
    AddExit("oeste", "./zona_guardabosques");
}


