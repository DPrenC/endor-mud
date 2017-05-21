/*
DESCRIPCION  : Senda por el bosque alrededor de la fortaleza de nandor
FICHERO      : senda2.c
Creacion	 : 5-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFS("senda");

create(){
    ::create();

    AddExit("nordeste",ROOMFS("senda1"));
    AddExit("sudeste",ROOMFS("senda3"));
    AnyadirPnjs();

}
