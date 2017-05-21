/****************************************************************************
Fichero: bosque018.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
Orilla sur del río.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/orilla");

create(){
    ::create();
    SetIntShort("la orilla sur del río Kandal");
    AddExit("este","./bosque019");
    AddExit("sudeste","./bosque026");
    AddExit("oeste","./bosque017");
    AddExit("suroeste","./bosque025");
}


