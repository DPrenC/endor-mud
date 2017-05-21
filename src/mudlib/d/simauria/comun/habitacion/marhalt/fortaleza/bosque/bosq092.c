/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq092.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq079"));
  AddExit("nordeste",ROOMFB("bosq081"));
  AddExit("sudeste",ROOMFB("bosq102"));
  AnyadirPnjs();
  }
