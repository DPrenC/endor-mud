/****************************************************************************
Fichero: bosque052.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque046");
    AddExit("nordeste","./bosque047");
    AddExit("oeste","./bosque051");
    AddExit("este","./bosque053");

}


