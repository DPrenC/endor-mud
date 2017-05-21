/*
DESCRIPCION  : Senda por el bosque alrededor de la fortaleza de nandor
FICHERO      : senda3.c
Creacion	 : 5-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFS("senda");

create(){
    ::create();

    AddExit("noroeste",ROOMFS("senda2"));
    AddExit("sudeste",ROOMFS("senda4"));
    AnyadirPnjs();
}
