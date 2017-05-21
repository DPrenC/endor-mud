/****************************************************************************
Fichero: bosque122.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque115");
    AddExit("norte","./bosque116");
    AddExit("nordeste","./bosque117");
    AddExit("sur","./bosque126");
    AddExit("sudeste","./bosque127");

}


