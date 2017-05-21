/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq062.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq056"));
  AddExit("sur",ROOMFB("bosq071"));
  AnyadirPnjs();
  }
