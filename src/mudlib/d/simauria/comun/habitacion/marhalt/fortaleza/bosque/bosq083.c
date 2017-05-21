/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq083.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq073"));
  AddExit("sur",ROOMFB("bosq094"));
  AnyadirPnjs();
  }
