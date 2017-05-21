/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq078.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq069"));
  AddExit("suroeste",ROOMFB("bosq089"));
  AddExit("sudeste",ROOMFB("bosq091"));
  AnyadirPnjs();
  }
