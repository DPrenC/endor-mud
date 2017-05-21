/****************************************************************************
Fichero: bosque063.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("nordeste","./bosque057");
    AddExit("oeste","./bosque062");
    AddExit("este","./bosque064");
    AddExit("suroeste","./bosque067");

}


