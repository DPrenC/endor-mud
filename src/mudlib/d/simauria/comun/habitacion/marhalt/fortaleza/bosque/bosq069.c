/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq069.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("este",ROOMFB("bosq070"));
  AddExit("suroeste",ROOMFB("bosq078"));
  AddExit("sur",ROOMFB("bosq079"));
  AddExit("sudeste",ROOMFB("bosq080"));
  AnyadirPnjs();
  }
