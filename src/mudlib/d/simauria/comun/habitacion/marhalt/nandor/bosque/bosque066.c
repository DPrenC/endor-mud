/****************************************************************************
Fichero: bosque066.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque059");
    AddExit("nordeste","./bosque060");
    AddExit("sur", "./bosque073");
    AddExit("suroeste", "./bosque072");
    AddExit("sudeste", "./bosque074");

}


