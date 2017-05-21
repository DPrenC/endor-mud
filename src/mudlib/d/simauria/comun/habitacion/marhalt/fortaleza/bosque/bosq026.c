/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq026.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq020"));
  AddExit("suroeste",ROOMFB("bosq033"));
  AddExit("sur",ROOMFB("bosq034"));
  AddExit("noroeste",ROOMFB("bosq019"));
  AnyadirPnjs();
  }
