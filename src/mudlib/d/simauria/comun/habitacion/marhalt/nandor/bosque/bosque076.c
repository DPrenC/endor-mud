/****************************************************************************
Fichero: bosque076.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/bosque_base");

create(){
    ::create();

    AddExit("norte","./bosque068");
    AddExit("suroeste","./bosque082");
    AddExit("sur", "./bosque083");

}


