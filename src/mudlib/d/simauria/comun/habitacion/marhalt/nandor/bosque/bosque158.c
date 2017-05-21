/****************************************************************************
Fichero: bosque158.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque151");
    AddExit("norte","./bosque152");
    AddExit("nordeste", "./bosque153");

}


