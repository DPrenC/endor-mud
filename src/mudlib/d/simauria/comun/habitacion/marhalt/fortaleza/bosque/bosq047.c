/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq047.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq040"));
  AddExit("noroeste",ROOMFB("bosq039"));
  AddExit("sur",ROOMFB("bosq054"));
  AnyadirPnjs();
  }
