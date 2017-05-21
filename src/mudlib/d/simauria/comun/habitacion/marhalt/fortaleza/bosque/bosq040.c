/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq040.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq032"));
  AddExit("sur",ROOMFB("bosq047"));
  AddExit("suroeste",ROOMFB("bosq046"));
  AnyadirPnjs();
  }
