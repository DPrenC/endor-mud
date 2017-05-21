/****************************************************************************
Fichero: bosque098.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque091");
    AddExit("oeste","./bosque097");
    AddExit("sur", "./bosque102");
    AddExit("sudeste", "./bosque103");

}


