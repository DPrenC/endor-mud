/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq108.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq099"));
  AddExit("este",ROOMFB("bosq109"));
  AddExit("sudeste",ROOMFB("bosq118"));
  AddExit("suroeste",ROOMFB("bosq117"));
  AnyadirPnjs();
  }
