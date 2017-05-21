/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq107.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq098"));
  AddExit("suroeste",ROOMFB("bosq116"));
  AddExit("sudeste",ROOMFS("senda1"));
  AnyadirPnjs();
  }
