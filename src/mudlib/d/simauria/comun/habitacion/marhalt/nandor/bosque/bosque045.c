/****************************************************************************
Fichero: bosque045.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque040");
    AddExit("oeste","./bosque044");
    AddExit("este","./bosque046");
    AddExit("sudeste","./bosque051");
}


