/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq089.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq078"));
  AddExit("sur",ROOMFB("bosq099"));
  AnyadirPnjs();
  }
