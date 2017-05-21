/*
DESCRIPCION  : Senda por el bosque alrededor de la fortaleza de nandor
FICHERO      : senda4.c
Creacion	 : 5-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFS("senda");

create(){
    ::create();

    AddExit("noroeste",ROOMFS("senda3"));
    AddExit("sur",ROOMFS("senda5"));
    AnyadirPnjs();
}
