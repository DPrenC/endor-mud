/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq119.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq110"));
  AddExit("sudeste",ROOMFB("bosq130"));
  AnyadirPnjs();
  }
