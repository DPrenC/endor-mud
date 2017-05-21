/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq057.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq052"));
  AddExit("suroeste",ROOMFB("bosq063"));
  AddExit("noroeste",ROOMFB("bosq051"));
  AddExit("sur",ROOMFB("bosq064"));
  AnyadirPnjs();
  }
