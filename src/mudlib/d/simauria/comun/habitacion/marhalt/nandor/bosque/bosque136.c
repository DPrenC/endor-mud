/****************************************************************************
Fichero: bosque136.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque130");
    AddExit("oeste","./bosque135");
    AddExit("sur","./bosque141");

}


