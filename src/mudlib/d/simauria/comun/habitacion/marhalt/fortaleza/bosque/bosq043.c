/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq043.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq037"));
  AddExit("norte",ROOMFB("bosq036"));
  AnyadirPnjs();
  }
