/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq130.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq119"));
  AddExit("nordeste",ROOMFB("bosq121"));
  AddExit("sudeste",ROOMFB("bosq137"));
  AddExit("suroeste",ROOMFB("bosq136"));
  AddExit("este",ROOMFB("bosq131"));
  AnyadirPnjs();
  }
