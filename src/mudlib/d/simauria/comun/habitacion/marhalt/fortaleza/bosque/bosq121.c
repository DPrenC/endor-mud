/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq121.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq110"));
  AddExit("suroeste",ROOMFB("bosq130"));
  AnyadirPnjs();
  }
