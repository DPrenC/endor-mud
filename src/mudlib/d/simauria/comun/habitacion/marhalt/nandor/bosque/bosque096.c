/****************************************************************************
Fichero: bosque096.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("este","./bosque097");
    AddExit("oeste","./bosque095");
    AddExit("nordeste", "./bosque091");
    AddExit("sur", "./bosque101");

}


