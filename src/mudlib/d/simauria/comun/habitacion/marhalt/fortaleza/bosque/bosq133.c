/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq133.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq124"));
  AddExit("norte",ROOMFB("bosq125"));
  AddExit("sudeste",ROOMFB("bosq138"));
  AnyadirPnjs();
  }
