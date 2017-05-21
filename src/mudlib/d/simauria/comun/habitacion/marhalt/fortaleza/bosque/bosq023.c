/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq023.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq018"));
  AddExit("sur",ROOMFB("bosq028"));
  AnyadirPnjs();
  }
