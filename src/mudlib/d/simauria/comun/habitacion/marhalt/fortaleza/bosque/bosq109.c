/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq109.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("oeste",ROOMFB("bosq108"));
  AnyadirPnjs();
  }
