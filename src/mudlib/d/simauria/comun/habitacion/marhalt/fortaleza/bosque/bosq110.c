/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq110.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq100"));
  AddExit("sudeste",ROOMFB("bosq121"));
  AddExit("suroeste",ROOMFB("bosq119"));
  AnyadirPnjs();
  }
