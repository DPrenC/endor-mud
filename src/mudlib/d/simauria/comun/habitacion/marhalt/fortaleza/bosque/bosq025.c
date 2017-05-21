/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq025.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq019"));
  AddExit("suroeste",ROOMFB("bosq032"));
  AddExit("sudeste",ROOMFB("bosq033"));
  AnyadirPnjs();
  }
