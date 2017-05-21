/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq020.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("suroeste",ROOMFB("bosq026"));
  AddExit("sur",ROOMFB("bosq027"));
  AddExit("noroeste",ROOMFB("bosq012"));
  AddExit("este",ROOMFB("bosq021"));
  AnyadirPnjs();
  }
