/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq066.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq058"));
  AddExit("nordeste",ROOMFB("bosq060"));
  AddExit("sudeste",ROOMFB("bosq075"));
  AnyadirPnjs();
  }
