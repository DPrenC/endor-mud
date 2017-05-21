/****************************************************************************
Fichero: bosque083.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("oeste","./bosque082");
    AddExit("norte","./bosque076");
    AddExit("suroeste","./bosque089");

}


