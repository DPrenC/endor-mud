/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq010.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("sudeste",ROOMFB("bosq017"));
  AddExit("nordeste",ROOMFB("bosq005"));
  AnyadirPnjs();
  }
