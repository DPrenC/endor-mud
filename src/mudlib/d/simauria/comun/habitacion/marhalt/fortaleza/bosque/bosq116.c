/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq116.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq106"));
  AddExit("nordeste",ROOMFB("bosq107"));
  AddExit("sur",ROOMFB("bosq125"));
  AnyadirPnjs();
  }
