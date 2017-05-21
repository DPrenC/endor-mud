/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq027.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("suroeste",ROOMFB("bosq034"));
  AddExit("norte",ROOMFB("bosq020"));
  AnyadirPnjs();
  }
