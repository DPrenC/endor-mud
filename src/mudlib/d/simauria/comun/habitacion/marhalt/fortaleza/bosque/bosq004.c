/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq004.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("este",ROOMFB("bosq005"));
  AddExit("oeste",ROOMFB("bosq003"));
  AnyadirPnjs();
  }
