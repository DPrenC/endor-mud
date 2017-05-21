/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq024.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq018"));
  AddExit("suroeste",ROOMFB("bosq029"));
  AddExit("sudeste",ROOMFB("bosq031"));
  AddExit("sur",ROOMFB("bosq030"));
  AnyadirPnjs();
  }
