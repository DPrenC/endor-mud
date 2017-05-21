/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq032.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq025"));
  AddExit("suroeste",ROOMFB("bosq039"));
  AddExit("sudeste",ROOMFB("bosq041"));
  AddExit("sur",ROOMFB("bosq040"));
  AnyadirPnjs();
  }
