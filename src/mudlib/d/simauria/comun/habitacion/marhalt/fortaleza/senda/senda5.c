/*
DESCRIPCION  : Senda por el bosque alrededor de la fortaleza de nandor
FICHERO      : senda6.c
Creacion	 : 5-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFS("senda");

create(){
    ::create();

    AddExit("norte",ROOMFS("senda4"));
    AddExit("sudeste",ROOMFS("senda6"));
    AnyadirPnjs();
}
