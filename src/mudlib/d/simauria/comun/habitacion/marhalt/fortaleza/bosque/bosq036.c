/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq036.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq030"));
  AddExit("noroeste",ROOMFB("bosq029"));
  AddExit("nordeste",ROOMFB("bosq031"));
  AddExit("sur",ROOMFB("bosq043"));
  AddExit("sudeste",ROOMFB("bosq044"));
  AnyadirPnjs();
  }
