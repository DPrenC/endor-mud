/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq013.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("sudeste",ROOMFB("bosq021"));
  AddExit("nordeste",ROOMFB("bosq007"));
  AnyadirPnjs();
  }
