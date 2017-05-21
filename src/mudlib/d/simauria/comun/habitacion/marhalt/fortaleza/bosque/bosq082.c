/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq082.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq071"));
  AddExit("norte",ROOMFB("bosq072"));
  AddExit("suroeste",ROOMFB("bosq093"));
  AddExit("sudeste",ROOMFB("bosq094"));
  AnyadirPnjs();
  }
