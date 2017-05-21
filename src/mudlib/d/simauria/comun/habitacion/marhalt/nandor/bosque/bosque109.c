/****************************************************************************
Fichero: bosque109.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque105");
    AddExit("norte","./bosque106");
    AddExit("sur","./bosque115");
    AddExit("sudeste","./bosque116");

}


