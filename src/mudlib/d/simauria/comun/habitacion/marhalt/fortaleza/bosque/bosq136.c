/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq136.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq130"));
  AddExit("sudeste",ROOMFB("bosq141"));
  AnyadirPnjs();
  }
