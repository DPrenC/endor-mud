/****************************************************************************
Fichero: bosque078.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque074");
    AddExit("este","./bosque079");
    AddExit("sur", "./bosque087");
    AddExit("sudeste", "./bosque088");
}


