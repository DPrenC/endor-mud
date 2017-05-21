/****************************************************************************
Fichero: bosque005.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("suroeste", "./bosque012");
    AddExit("este","./bosque006");
    AddExit("sur","./bosque013");
    AddExit("noroeste", CNSH("camino07"));
    AddExit("norte", CNSH("camino08"));

}


