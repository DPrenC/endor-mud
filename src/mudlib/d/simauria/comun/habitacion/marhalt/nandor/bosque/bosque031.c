/****************************************************************************
Fichero: bosque031.c
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
    AddExit("este","./bosque032");
    AddExit("suroeste","./bosque036");
    AddExit("sur","./bosque037");
    AddItem(PNJ("marhalt/bicho_orilla"),REFRESH_DESTRUCT, 1);
}


