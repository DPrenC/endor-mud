/****************************************************************************
Fichero: camino15.c
Autor: Ratwor
Fecha: 24/12/2007
Descripción: El camino del castillo
****************************************************************************/

#include "./path.h"

inherit CASTILLO("camino/junto_foso");
create(){
    ::create();
    SetIntLong(QueryIntLong()+" Junto a tí, sobrepasándote multitud de metros por "
    "encima de tu cabeza, puedes apreciar en todo su esplendor el enorme torreón de Cónor.\n");
    AddExit("norte", "./camino16");
    AddExit("este", "./camino14");
}

