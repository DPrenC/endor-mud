/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq031.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq024"));
  AddExit("suroeste",ROOMFB("bosq036"));
  AddExit("sudeste",ROOMFB("bosq038"));
  AddExit("sur",ROOMFB("bosq037"));
  AnyadirPnjs();
  }
