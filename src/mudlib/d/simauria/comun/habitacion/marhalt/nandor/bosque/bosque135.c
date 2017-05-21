/****************************************************************************
Fichero: bosque135.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque129");
    AddExit("norte","./bosque130");
    AddExit("este","./bosque136");
    AddExit("sudeste", "./bosque141");
}


