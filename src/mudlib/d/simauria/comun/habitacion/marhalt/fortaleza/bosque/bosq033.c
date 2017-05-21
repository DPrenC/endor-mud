/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq033.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq026"));
  AddExit("suroeste",ROOMFB("bosq041"));
  AddExit("sur",ROOMFB("bosq042"));
  AddExit("noroeste",ROOMFB("bosq025"));
  AnyadirPnjs();
  }
