/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq126.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq117"));
  AddExit("este",ROOMFB("bosq127"));
  AnyadirPnjs();
  }
