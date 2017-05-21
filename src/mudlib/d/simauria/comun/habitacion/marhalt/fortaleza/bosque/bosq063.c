/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq063.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq057"));
  AddExit("noroeste",ROOMFB("bosq055"));
  AddExit("sur",ROOMFB("bosq072"));
  AnyadirPnjs();
  }
