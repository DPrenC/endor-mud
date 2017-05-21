/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq095.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq084"));
  AddExit("nordeste",ROOMFB("bosq086"));
  AddExit("sudeste",ROOMFB("bosq104"));
  AnyadirPnjs();
  }
