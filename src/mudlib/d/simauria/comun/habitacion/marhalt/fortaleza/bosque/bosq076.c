/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq076.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq067"));
  AddExit("norte",ROOMFB("bosq068"));
  AddExit("este",ROOMFB("bosq077"));
  AddExit("suroeste",ROOMFB("bosq085"));
  AddExit("sudeste",ROOMFB("bosq087"));
  AnyadirPnjs();
  }
