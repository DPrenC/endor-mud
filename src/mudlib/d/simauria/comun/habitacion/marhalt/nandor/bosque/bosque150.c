/****************************************************************************
Fichero: bosque150.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque142");
    AddExit("nordeste","./bosque143");
    AddExit("oeste","./bosque149");
    AddExit("sur","./bosque157");

}


