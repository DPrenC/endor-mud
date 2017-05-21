/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq125.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq116"));
  AddExit("sur",ROOMFB("bosq133"));
  AnyadirPnjs();
  }
