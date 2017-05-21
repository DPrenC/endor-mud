/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq138.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq133"));
  AddExit("sudeste",ROOMFB("bosq142"));
  AnyadirPnjs();
  }
