/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq141.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq136"));
  AddExit("nordeste",ROOMFB("bosq137"));
  AddExit("suroeste",ROOMFB("bosq144"));
  AnyadirPnjs();
  }
