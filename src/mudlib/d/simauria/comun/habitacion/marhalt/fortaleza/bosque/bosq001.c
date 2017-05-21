/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq001.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("este",ROOMFB("bosq002"));
  AddExit("suroeste",ROOMFB("bosq006"));
  AddExit("sur",ROOMFB("bosq007"));
  AddExit("sudeste",ROOMFB("bosq008"));
  AnyadirPnjs();
  }
