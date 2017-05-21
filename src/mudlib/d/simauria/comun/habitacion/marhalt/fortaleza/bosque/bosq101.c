/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq101.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq091"));
  AddExit("nordeste",ROOMFB("bosq093"));
  AddExit("sur",ROOMFB("bosq111"));
  AnyadirPnjs();
  }
