/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq094.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq082"));
  AddExit("norte",ROOMFB("bosq083"));
  AddExit("suroeste",ROOMFB("bosq103"));
  AnyadirPnjs();
  }
