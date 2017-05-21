/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq006.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("sudeste",ROOMFB("bosq014"));
  AddExit("suroeste",ROOMFB("bosq012"));
  AddExit("nordeste",ROOMFB("bosq001"));
  AnyadirPnjs();
  }
