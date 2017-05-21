/****************************************************************************
Fichero: bosque080.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("este","./bosque081");
    AddExit("oeste","./bosque079");
    AddExit("suroeste","./bosque088");
    AddExit("nordeste","./bosque075");

}


