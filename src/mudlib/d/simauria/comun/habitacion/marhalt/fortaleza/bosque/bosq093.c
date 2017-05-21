/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq093.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq080"));
  AddExit("norte",ROOMFB("bosq081"));
  AddExit("nordeste",ROOMFB("bosq082"));
  AddExit("sudeste",ROOMFB("bosq103"));
  AddExit("suroeste",ROOMFB("bosq101"));
  AnyadirPnjs();
  }
