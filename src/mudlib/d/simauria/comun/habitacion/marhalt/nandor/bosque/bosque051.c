/****************************************************************************
Fichero: bosque051.c
utor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque046");
    AddExit("noroeste","./bosque045");
    AddExit("sur","./bosque056");
    AddExit("este","./bosque052");

}


