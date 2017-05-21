/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq086.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("suroeste",ROOMFB("bosq095"));
  AddExit("noroeste",ROOMFB("bosq075"));
  AddExit("sur",ROOMFB("bosq096"));
  AnyadirPnjs();
  }
