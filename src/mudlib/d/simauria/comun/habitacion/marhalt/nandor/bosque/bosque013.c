/****************************************************************************
Fichero: bosque013.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque005");
    AddExit("oeste","./bosque012");
    AddExit("suroeste", "./bosque015");
    AddExit("nordeste", "./bosque006");
}


