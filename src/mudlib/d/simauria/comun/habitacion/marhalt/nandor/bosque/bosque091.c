/****************************************************************************
Fichero: bosque091.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque087");
    AddExit("nordeste","./bosque088");
    AddExit("suroeste", "./bosque096");
    AddExit("sur", "./bosque097");
    AddExit("sudeste", "./bosque098");

}


