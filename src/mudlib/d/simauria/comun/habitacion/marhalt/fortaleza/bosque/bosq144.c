/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq144.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq141"));
  AddExit("suroeste",ROOMFB("bosq145"));
  AnyadirPnjs();
  }
