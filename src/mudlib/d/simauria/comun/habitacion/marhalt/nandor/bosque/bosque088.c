/****************************************************************************
Fichero: bosque088.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque078");
    AddExit("norte","./bosque079");
    AddExit("nordeste", "./bosque080");
    AddExit("oeste", "./bosque087");
    AddExit("suroeste", "./bosque091");

}


