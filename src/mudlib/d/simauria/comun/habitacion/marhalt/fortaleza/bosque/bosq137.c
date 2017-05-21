/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq137.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq130"));
  AddExit("nordeste",ROOMFB("bosq132"));
  AddExit("suroeste",ROOMFB("bosq141"));
  AnyadirPnjs();
  }
