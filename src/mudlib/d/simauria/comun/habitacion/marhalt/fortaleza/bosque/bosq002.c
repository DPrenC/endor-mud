/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq002.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("este",ROOMFB("bosq003"));
  AddExit("oeste",ROOMFB("bosq001"));
  AnyadirPnjs();
  }
