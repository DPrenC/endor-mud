/****************************************************************************
Fichero: senda14.c
Autor: Buh
Fecha: 01/04/2007
Descripción: La senda que va hacia la fortaleza de cored.
****************************************************************************/


#include "./path.h"
inherit ROOMFS("senda");

create(){
    ::create();
    AddExit("noroeste",ROOMFS("senda13"));
    AddExit("sudeste", ROOMFS("senda15"));
    AnyadirPnjs();
}
