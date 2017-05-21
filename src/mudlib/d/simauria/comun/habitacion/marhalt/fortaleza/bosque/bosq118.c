/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq118.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq108"));
  AddExit("sur",ROOMFB("bosq129"));
  AnyadirPnjs();
  }
