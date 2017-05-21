/****************************************************************************
Fichero: bosque152.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque144");
    AddExit("oeste","./bosque151");
    AddExit("este","./bosque153");
    AddExit("sur","./bosque158");

}


