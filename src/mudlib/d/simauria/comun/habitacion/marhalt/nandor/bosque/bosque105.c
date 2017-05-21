/****************************************************************************
Fichero: bosque105.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("nordeste","./bosque101");
    AddExit("este","./bosque106");
    AddExit("sudeste","./bosque109");
    AddExit("noroeste", CNS("cam23"));
    AddExit("oeste", CNS("cam24"));
    AddExit("suroeste", CNS("cam25"));

}


