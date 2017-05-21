/****************************************************************************
Fichero: bosque115.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque109");
    AddExit("este","./bosque116");
    AddExit("suroeste","./bosque121");
    AddExit("sudeste","./bosque122");

}


