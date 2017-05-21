/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq071.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq062"));
  AddExit("noroeste",ROOMFB("bosq061"));
  AddExit("suroeste",ROOMFB("bosq080"));
  AddExit("sudeste",ROOMFB("bosq082"));
  AnyadirPnjs();
  }
