/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq077.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("oeste",ROOMFB("bosq076"));
  AddExit("suroeste",ROOMFB("bosq086"));
  AddExit("sur",ROOMFB("bosq087"));
  AddExit("sudeste",ROOMFB("bosq088"));
  AnyadirPnjs();
  }
