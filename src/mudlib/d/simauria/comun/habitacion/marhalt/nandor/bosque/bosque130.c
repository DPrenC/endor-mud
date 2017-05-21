/****************************************************************************
Fichero: bosque130.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque123");
    AddExit("norte","./bosque124");
    AddExit("oeste","./bosque129");
    AddExit("sur","./bosque135");
    AddExit("sudeste","./bosque136");

}


