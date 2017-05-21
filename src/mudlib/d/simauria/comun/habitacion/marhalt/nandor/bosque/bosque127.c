/****************************************************************************
Fichero: bosque127.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque122");
    AddExit("oeste","./bosque126");
    AddExit("este","./bosque128");
    AddExit("suroeste","./bosque134");
    AddExit("nordeste", "./zona_guardabosques");
}


