/****************************************************************************
Fichero: bosque126.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque122");
    AddExit("este","./bosque127");
    AddExit("suroeste","./bosque133");
    AddExit("sur","./bosque134");

}


