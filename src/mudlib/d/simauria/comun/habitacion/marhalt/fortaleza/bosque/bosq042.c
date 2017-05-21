/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq042.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq033"));
  AddExit("suroeste",ROOMFB("bosq048"));
  AnyadirPnjs();
  }
