/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq135.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq128"));
  AddExit("sudeste",ROOMFB("bosq140"));
  AddExit("suroeste",ROOMFB("bosq139"));
  AnyadirPnjs();
  }
