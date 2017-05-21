/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq122.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq113"));
  AddExit("suroeste",ROOMFB("bosq131"));
  AnyadirPnjs();
  }
