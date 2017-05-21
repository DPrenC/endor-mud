/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq096.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq086"));
  AddExit("sudeste",ROOMFB("bosq105"));
  AnyadirPnjs();
  }
