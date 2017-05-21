/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq050.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq044"));
  AddExit("nordeste",ROOMFB("bosq045"));
  AddExit("sudeste",ROOMFB("bosq056"));
  AnyadirPnjs();
  }
