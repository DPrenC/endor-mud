/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq058.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq053"));
  AddExit("sudeste",ROOMFB("bosq066"));
  AddExit("sur",ROOMFB("bosq065"));
  AnyadirPnjs();
  }
