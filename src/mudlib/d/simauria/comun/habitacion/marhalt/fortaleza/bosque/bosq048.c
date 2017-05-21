/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq048.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq041"));
  AddExit("nordeste",ROOMFB("bosq042"));
  AnyadirPnjs();
  }
