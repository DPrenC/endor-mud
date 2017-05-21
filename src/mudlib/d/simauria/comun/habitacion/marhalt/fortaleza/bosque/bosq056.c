/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq056.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq052"));
  AddExit("suroeste",ROOMFB("bosq062"));
  AddExit("noroeste",ROOMFB("bosq050"));
  AddExit("sudeste",ROOMFB("bosq064"));
  AnyadirPnjs();
  }
