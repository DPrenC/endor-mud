/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq090.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("suroeste",ROOMFB("bosq099"));
  AddExit("sur",ROOMFB("bosq100"));
  AddExit("nordeste",ROOMFB("bosq079"));
  AnyadirPnjs();
  }
