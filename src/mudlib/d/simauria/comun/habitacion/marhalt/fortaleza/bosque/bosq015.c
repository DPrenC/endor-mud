/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq015.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq009"));
  AddExit("suroeste",ROOMFB("bosq021"));
  AnyadirPnjs();
  }
