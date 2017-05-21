/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq117.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq108"));
  AddExit("suroeste",ROOMFB("bosq126"));
  AnyadirPnjs();
  }
