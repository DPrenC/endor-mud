/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq019.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("sudeste",ROOMFB("bosq026"));
  AddExit("suroeste",ROOMFB("bosq025"));
  AddExit("nordeste",ROOMFB("bosq012"));
  AnyadirPnjs();
  }
