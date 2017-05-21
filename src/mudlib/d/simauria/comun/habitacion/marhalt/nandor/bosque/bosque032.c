/****************************************************************************
Fichero: bosque032.c
Autor: Ratwor
Fecha: 09/12/2006
Descripci�n: El bosque de Marhalt.
Orilla sur del r�o.
****************************************************************************/

#include "./path.h"

inherit MARH("nandor/bosque/orilla");

create(){
    ::create();
    SetIntShort("la orilla sur del r�o Kandal");
    AddExit("este","./bosque033");
    AddExit("oeste","./bosque031");
    AddExit("suroeste", "./bosque037");
    AddExit("sudeste", "./bosque038");
}


