/****************************************************************************
Fichero: bosque072.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("oeste","./bosque071");
    AddExit("este","./bosque073");
    AddExit("sur", "./bosque077");
    AddExit("nordeste", "./bosque066");

}


