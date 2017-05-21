/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq111.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq101"));
  AddExit("suroeste",ROOMFB("bosq120"));
  AnyadirPnjs();
  }
