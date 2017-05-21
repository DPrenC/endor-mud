/****************************************************************************
Fichero: bosque099.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("nordeste","./bosque092");
    AddExit("este","./bosque100");
    AddExit("suroeste", "./bosque103");
    AddExit("sur", "./bosque104");
}


