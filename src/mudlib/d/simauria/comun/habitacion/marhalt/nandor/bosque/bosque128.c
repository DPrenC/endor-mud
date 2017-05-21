/****************************************************************************
Fichero: bosque128.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("nordeste","./bosque123");
    AddExit("oeste","./bosque127");
    AddExit("este","./bosque129");
    AddExit("norte", "./zona_guardabosques");
}


