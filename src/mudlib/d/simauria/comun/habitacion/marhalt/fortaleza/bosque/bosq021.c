/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq021.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq015"));
  AddExit("noroeste",ROOMFB("bosq013"));
  AddExit("oeste",ROOMFB("bosq020"));
  AnyadirPnjs();
  }
