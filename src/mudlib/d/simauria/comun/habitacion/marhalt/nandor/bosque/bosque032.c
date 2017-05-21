/****************************************************************************
Fichero: bosque032.c
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
    AddExit("este","./bosque033");
    AddExit("oeste","./bosque031");
    AddExit("suroeste", "./bosque037");
    AddExit("sudeste", "./bosque038");
}


