/****************************************************************************
Fichero: bosque129.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque123");
    AddExit("nordeste","./bosque124");
    AddExit("oeste","./bosque128");
    AddExit("este","./bosque130");
    AddExit("sudeste","./bosque135");
    AddExit("noroeste", "./zona_guardabosques");
}


