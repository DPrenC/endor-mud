/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq084.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq074"));
  AddExit("nordeste",ROOMFB("bosq075"));
  AddExit("sudeste",ROOMFB("bosq095"));
  AnyadirPnjs();
  }
