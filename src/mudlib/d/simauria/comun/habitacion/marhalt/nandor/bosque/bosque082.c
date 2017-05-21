/****************************************************************************
Fichero: bosque082.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("este","./bosque083");
    AddExit("oeste","./bosque081");
    AddExit("sur","./bosque089");
    AddExit("nordeste","./bosque076");
    AddExit("noroeste","./bosque075");
}


