/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq102.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq092"));
  AddExit("sudeste",ROOMFB("bosq113"));
  AnyadirPnjs();
  }
