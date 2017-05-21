/****************************************************************************
Fichero: bosque101.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque095");
    AddExit("norte","./bosque096");
    AddExit("nordeste","./bosque097");
    AddExit("suroeste","./bosque105");
    AddExit("sur","./bosque106");

}


