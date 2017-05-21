/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq104.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq095"));
  AddExit("sudeste",ROOMFB("bosq114"));
  AnyadirPnjs();
  }
