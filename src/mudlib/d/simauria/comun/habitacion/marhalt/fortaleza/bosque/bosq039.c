/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq039.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq032"));
  AddExit("sur",ROOMFB("bosq046"));
  AddExit("sudeste",ROOMFB("bosq047"));
  AnyadirPnjs();
  }
