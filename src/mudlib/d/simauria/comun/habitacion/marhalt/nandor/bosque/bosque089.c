/****************************************************************************
Fichero: bosque089.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque081");
    AddExit("norte","./bosque082");
    AddExit("nordeste", "./bosque083");
    AddExit("sur", "./bosque092");
    AddExit("sudeste", "./bosque093");
}


