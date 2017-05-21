/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq005.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("sudeste",ROOMFB("bosq011"));
  AddExit("suroeste",ROOMFB("bosq010"));
  AddExit("oeste",ROOMFB("bosq004"));
  AnyadirPnjs();
  }
