/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq112.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq103"));
  AddExit("sudeste",ROOMFB("bosq123"));
  AnyadirPnjs();
  }
