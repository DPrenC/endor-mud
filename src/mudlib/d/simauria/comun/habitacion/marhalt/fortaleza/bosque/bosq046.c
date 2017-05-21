/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq046.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq039"));
  AddExit("sudeste",ROOMFB("bosq054"));
  AddExit("nordeste",ROOMFB("bosq040"));
  AddExit("sur",ROOMFB("bosq053"));
  AnyadirPnjs();
  }
