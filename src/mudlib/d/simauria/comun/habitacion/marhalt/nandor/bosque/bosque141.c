/****************************************************************************
Fichero: bosque141.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("noroeste","./bosque135");
    AddExit("norte","./bosque136");
    AddExit("suroeste","./bosque147");
    AddExit("sur","./bosque148");

}


