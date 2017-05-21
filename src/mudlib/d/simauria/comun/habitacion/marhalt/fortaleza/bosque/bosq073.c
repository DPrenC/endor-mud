/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq073.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq064"));
  AddExit("sur",ROOMFB("bosq083"));
  AnyadirPnjs();
  }
