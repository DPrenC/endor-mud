/****************************************************************************
Fichero: bosque059.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque054");
    AddExit("norte","./bosque055");
    AddExit("este","./bosque060");
    AddExit("sur","./bosque066");

}


