/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq038.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq031"));
  AddExit("suroeste",ROOMFB("bosq044"));
  AddExit("sudeste",ROOMFB("bosq045"));
  AnyadirPnjs();
  }
