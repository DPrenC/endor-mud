/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq014.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq006"));
  AnyadirPnjs();
  }
