/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq105.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq096"));
  AddExit("sudeste",ROOMFB("bosq115"));
  AnyadirPnjs();
  }
