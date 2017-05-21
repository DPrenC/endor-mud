/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq143.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq139"));
  AddExit("nordeste",ROOMFB("bosq140"));
  AnyadirPnjs();
  }
