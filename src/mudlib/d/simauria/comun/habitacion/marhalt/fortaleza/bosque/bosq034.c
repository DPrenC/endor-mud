/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq034.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq027"));
  AddExit("norte",ROOMFB("bosq026"));
  AnyadirPnjs();
  }
