/****************************************************************************
Fichero: bosque006.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("oeste","./bosque005");
    AddExit("sudeste","./bosque014");
    AddExit("suroeste", "./bosque013");
    AddExit("norte", CNSH("camino09"));
    AddExit("nordeste", CNSH("camino10"));

}


