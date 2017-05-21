/****************************************************************************
Fichero: bosque112.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("nordeste","./bosque108");
    AddExit("oeste","./bosque111");
    AddExit("sur","./bosque118");
    AddExit("sudeste","./bosque119");

}


