/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq054.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq047"));
  AddExit("sur",ROOMFB("bosq059"));
  AddExit("noroeste",ROOMFB("bosq046"));
  AddExit("sudeste",ROOMFB("bosq060"));
  AnyadirPnjs();
  }
