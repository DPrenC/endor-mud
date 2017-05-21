/****************************************************************************
Fichero: camino17.c
Autor: Ratwor
Fecha: 24/12/2007
Descripci�n: El camino del castillo
****************************************************************************/

#include "./path.h"
inherit CASTILLO("camino/junto_foso");
create(){
    ::create();
    SetIntLong(QueryIntLong()+" Junto a t�, sobrepas�ndote multitud de metros por "
    "encima de tu cabeza, puedes apreciar en todo su esplendor el enorme torre�n de C�nor.\n");
    AddExit("oeste", "./camino18");
    AddExit("sudeste", "./camino16");
}

