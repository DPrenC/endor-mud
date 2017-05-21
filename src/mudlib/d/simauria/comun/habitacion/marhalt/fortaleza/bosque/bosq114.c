/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq114.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq104"));
  AddExit("nordeste",ROOMFB("bosq106"));
  AddExit("sudeste",ROOMFB("bosq124"));
  AnyadirPnjs();
  }
