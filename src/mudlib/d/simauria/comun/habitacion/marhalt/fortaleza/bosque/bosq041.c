/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq041.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq033"));
  AddExit("sur",ROOMFB("bosq048"));
  AddExit("noroeste",ROOMFB("bosq032"));
  AnyadirPnjs();
  }
