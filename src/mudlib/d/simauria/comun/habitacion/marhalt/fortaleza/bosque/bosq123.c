/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq123.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq112"));
  AddExit("suroeste",ROOMFB("bosq132"));
  AnyadirPnjs();
  }
