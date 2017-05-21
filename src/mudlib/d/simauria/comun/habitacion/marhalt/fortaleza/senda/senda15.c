/****************************************************************************
Fichero: senda15.c
Autor: Ratwor
Fecha: 01/04/2007
Descripción: La senda que va hacia la fortaleza de cored.
****************************************************************************/


#include "./path.h"
inherit ROOMFS("senda");

create(){
    ::create();
    AddExit("noroeste",ROOMFS("senda14"));
    AddExit("sur",ROOMFS("senda16"));
    AnyadirPnjs();
}
