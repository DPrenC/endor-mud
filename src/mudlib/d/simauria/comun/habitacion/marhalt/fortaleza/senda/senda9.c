/****************************************************************************
Fichero: senda9.c
Autor: Buh
Fecha: 01/04/2007
Descripción: La senda que va hacia la fortaleza de cored.
****************************************************************************/


#include "./path.h"
inherit ROOMFS("senda");

create(){
    ::create();
    AddExit("norte",ROOMFS("senda8"));
    AddExit("suroeste", ROOMFS("senda10"));
    AnyadirPnjs();
}
