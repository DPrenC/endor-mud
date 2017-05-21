/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq140.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq135"));
  AddExit("suroeste",ROOMFB("bosq143"));
  AnyadirPnjs();
  }
