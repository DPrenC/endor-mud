/****************************************************************************
Fichero: bosque092.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque089");
    AddExit("este","./bosque093");
    AddExit("suroeste", "./bosque099");
    AddExit("sur", "./bosque100");

}


