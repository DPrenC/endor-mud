/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq012.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("sudeste",ROOMFB("bosq020"));
  AddExit("suroeste",ROOMFB("bosq019"));
  AddExit("nordeste",ROOMFB("bosq006"));
  AnyadirPnjs();
  }
