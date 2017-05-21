/****************************************************************************
Fichero: bosque074.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste", "./bosque066");
    AddExit("oeste","./bosque073");
    AddExit("sur","./bosque078");
    AddExit("sudeste", "./bosque079");

}


