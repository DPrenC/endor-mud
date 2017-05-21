/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq068.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("oeste",ROOMFB("bosq067"));
  AddExit("sur",ROOMFB("bosq076"));
  AnyadirPnjs();
  }
