/****************************************************************************
Fichero: bosque079.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("este","./bosque080");
    AddExit("oeste","./bosque078");
    AddExit("sur", "./bosque088");
    AddExit("noroeste", "./bosque074");
    AddExit("suroeste", "./bosque087");
}


