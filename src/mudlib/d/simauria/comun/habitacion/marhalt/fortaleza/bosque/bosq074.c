/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq074.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq065"));
  AddExit("sudeste",ROOMFB("bosq084"));
  AnyadirPnjs();
  }
