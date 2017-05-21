/****************************************************************************
Fichero: bosque044.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("este","./bosque045");
    AddExit("oeste","./bosque043");
    AddExit("suroeste","./bosque050");
    AddExit("nordeste", "./bosque040");
}


