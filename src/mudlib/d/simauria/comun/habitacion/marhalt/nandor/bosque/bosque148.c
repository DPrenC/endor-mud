/****************************************************************************
Fichero: bosque148.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque141");
    AddExit("oeste","./bosque147");
    AddExit("suroeste","./bosque155");
    AddExit("sur","./bosque156");

}


