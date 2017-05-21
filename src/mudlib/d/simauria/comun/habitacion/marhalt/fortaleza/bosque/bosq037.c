/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq037.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq031"));
  AddExit("suroeste",ROOMFB("bosq043"));
  AddExit("sur",ROOMFB("bosq044"));
  AnyadirPnjs();
  }
