/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq139.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq135"));
  AddExit("sudeste",ROOMFB("bosq143"));
  AnyadirPnjs();
  }
