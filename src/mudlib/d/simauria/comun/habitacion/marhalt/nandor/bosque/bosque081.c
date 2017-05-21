/****************************************************************************
Fichero: bosque081.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("este","./bosque082");
    AddExit("oeste","./bosque080");
    AddExit("norte","./bosque075");
    AddExit("sudeste","./bosque089");

}


