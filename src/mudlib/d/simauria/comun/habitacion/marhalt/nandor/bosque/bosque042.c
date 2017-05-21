/****************************************************************************
Fichero: bosque042.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque038");
    AddExit("oeste","./bosque041");
    AddExit("suroeste","./bosque048");
    AddExit("sur", "./zona_lenyador");
}


