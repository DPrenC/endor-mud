/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq067.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq059"));
  AddExit("norte",ROOMFB("bosq060"));
  AddExit("este",ROOMFB("bosq068"));
  AddExit("sudeste",ROOMFB("bosq076"));
  AnyadirPnjs();
  }
