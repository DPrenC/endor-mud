/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq145.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq144"));
AddExit("sudeste",QUEST+"/tamara/hilander");
  AnyadirPnjs();
  }
