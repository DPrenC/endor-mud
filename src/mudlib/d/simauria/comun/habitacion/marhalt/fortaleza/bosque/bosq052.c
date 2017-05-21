/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq052.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq045"));
  AddExit("suroeste",ROOMFB("bosq056"));
  AddExit("sur",ROOMFB("bosq057"));
  AnyadirPnjs();
  }
