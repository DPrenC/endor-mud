/****************************************************************************
Fichero: bosque061.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque056");
    AddExit("oeste","./bosque060");
    AddExit("este","./bosque062");

}


