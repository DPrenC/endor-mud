/****************************************************************************
Fichero: bosque075.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque067");
    AddExit("suroeste","./bosque080");
    AddExit("sur", "./bosque081");
    AddExit("sudeste", "./bosque082");

}


