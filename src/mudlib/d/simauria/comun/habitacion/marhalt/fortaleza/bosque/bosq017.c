/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq017.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq010"));
  AddExit("nordeste",ROOMFB("bosq011"));
  AddExit("sur",ROOMFB("bosq022"));
  AnyadirPnjs();
  }
