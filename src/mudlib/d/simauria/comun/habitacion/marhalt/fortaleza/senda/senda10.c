/****************************************************************************
Fichero: senda10.c
Autor: Buh
Fecha: 01/04/2007
Descripción: La senda que va hacia la fortaleza de cored.
****************************************************************************/


#include "./path.h"
inherit ROOMFS("senda");

create(){
    ::create();
    AddExit("nordeste",ROOMFS("senda9"));
    AddExit("sur", ROOMFS("senda11"));
    AnyadirPnjs();
}
