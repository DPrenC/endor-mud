/****************************************************************************
Fichero: bosque009.c
Autor: Ratwor
Fecha: 09/12/2006
Descripción: El bosque de Marhalt.
Orilla norte del río.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/orilla");

create(){
    ::create();
    SetIntShort("la orilla norte del río Kandal");
    AddExit("oeste","./bosque008");
    AddExit("este","./bosque010");
    AddExit("noroeste", "./bosque002");
    AddExit("nordeste", "./bosque003");
}


