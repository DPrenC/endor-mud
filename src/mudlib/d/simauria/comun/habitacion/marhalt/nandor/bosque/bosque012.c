/****************************************************************************
Fichero: bosque012.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("nordeste", "./bosque005");
    AddExit("oeste","./bosque011");
    AddExit("este","./bosque013");
    AddExit("sur", "./bosque015");
}


