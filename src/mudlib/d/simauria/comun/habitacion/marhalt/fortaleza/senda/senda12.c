/****************************************************************************
Fichero: senda12.c
Autor: Buh
Fecha: 01/04/2007
Descripción: La senda que va hacia la fortaleza de cored.
****************************************************************************/


#include "./path.h"
inherit ROOMFS("senda");

create(){
    ::create();
    AddExit("norte",ROOMFS("senda11"));
    AddExit("sudeste", ROOMFS("senda13"));
    AnyadirPnjs();
}
