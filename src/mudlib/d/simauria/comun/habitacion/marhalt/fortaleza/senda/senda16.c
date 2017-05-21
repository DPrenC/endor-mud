/****************************************************************************
Fichero: senda16.c
Autor: Ratwor
Fecha: 28/12/2007
Descripción: La senda que va hacia la fortaleza de cored.
****************************************************************************/


#include "./path.h"
inherit ROOMFS("senda");

create(){
    ::create();
    AddExit("norte",ROOMFS("senda15"));
    AddExit("suroeste",ROOMFS("senda17"));
    AnyadirPnjs();
}
