/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq003.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("este",ROOMFB("bosq004"));
  AddExit("oeste",ROOMFB("bosq002"));
  AddExit("sur",ROOMFB("bosq009"));
  AnyadirPnjs();
  }
