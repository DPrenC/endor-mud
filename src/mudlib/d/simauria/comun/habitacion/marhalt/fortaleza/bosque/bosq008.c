/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq008.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq001"));
  AnyadirPnjs();
  }
