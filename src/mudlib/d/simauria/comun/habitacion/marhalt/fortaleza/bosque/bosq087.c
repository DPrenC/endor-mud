/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq087.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq076"));
  AddExit("norte",ROOMFB("bosq077"));
  AddExit("este",ROOMFB("bosq088"));
  AddExit("sudeste",ROOMFB("bosq097"));
  AnyadirPnjs();
  }
