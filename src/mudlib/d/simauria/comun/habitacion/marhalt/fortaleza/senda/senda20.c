/****************************************************************************
Fichero: senda20.c
Autor: Ratwor
Fecha: 28/12/2007
Descripción: La senda que va hacia la fortaleza de cored.
****************************************************************************/


#include "./path.h"
inherit ROOMFS("senda");

create(){
    ::create();
    SetIntLong(QueryIntLong()+" Hacia el suroeste la senda termina en un ancho camino.\n");
    AddExit("norte",ROOMFS("senda19"));
    AddExit("suroeste", CAMINOS "/norte_marhalt/camino32");
    AnyadirPnjs();
}
