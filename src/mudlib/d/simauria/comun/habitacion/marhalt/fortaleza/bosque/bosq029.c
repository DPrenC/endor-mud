/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq029.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("sudeste",ROOMFB("bosq036"));
  AddExit("nordeste",ROOMFB("bosq024"));
  AddExit("sur",ROOMFB("bosq035"));
  AnyadirPnjs();
  }
