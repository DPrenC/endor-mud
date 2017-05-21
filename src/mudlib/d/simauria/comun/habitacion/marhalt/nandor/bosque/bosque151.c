/****************************************************************************
Fichero: bosque151.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque143");
    AddExit("norte","./bosque144");
    AddExit("este","./bosque152");
    AddExit("sudeste","./bosque158");

}


