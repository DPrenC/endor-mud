/****************************************************************************
Fichero: senda19.c
Autor: Ratwor
Fecha: 28/12/2007
Descripción: La senda que va hacia la fortaleza de cored.
****************************************************************************/


#include "./path.h"
inherit ROOMFS("senda");

create(){
    ::create();
    AddExit("nordeste",ROOMFS("senda18"));
    AddExit("sur",ROOMFS("senda20"));
    AnyadirPnjs();
}
