/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq011.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("sudeste",ROOMFB("bosq018"));
  AddExit("suroeste",ROOMFB("bosq017"));
  AddExit("noroeste",ROOMFB("bosq005"));
  AnyadirPnjs();
  }
