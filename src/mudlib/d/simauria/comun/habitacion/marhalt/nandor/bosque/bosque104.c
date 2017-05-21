/****************************************************************************
Fichero: bosque104.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque099");
    AddExit("nordeste","./bosque100");
    AddExit("oeste","./bosque103");
    AddExit("suroeste","./bosque107");
    AddExit("sudeste","./bosque108");

}


