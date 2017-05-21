/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq045.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq038"));
  AddExit("suroeste",ROOMFB("bosq050"));
  AddExit("sudeste",ROOMFB("bosq052"));
  AddExit("sur",ROOMFB("bosq051"));
  AnyadirPnjs();
  }
