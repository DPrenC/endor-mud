/****************************************************************************
Fichero: bosque134.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque126");
    AddExit("nordeste","./bosque127");
    AddExit("oeste","./bosque133");
    AddExit("sur","./bosque138");
    AddExit("sudeste","./bosque139");

}


