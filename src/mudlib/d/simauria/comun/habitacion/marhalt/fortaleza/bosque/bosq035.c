/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq035.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq029"));
  AnyadirPnjs();
 SetExplorable(1);
  }
