/****************************************************************************
Fichero: bosque116.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque109");
    AddExit("nordeste","./bosque110");
    AddExit("oeste","./bosque115");
    AddExit("este","./bosque117");
    AddExit("sur","./bosque122");

}


