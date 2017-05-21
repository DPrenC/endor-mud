/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq064.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq057"));
  AddExit("suroeste",ROOMFB("bosq072"));
  AddExit("noroeste",ROOMFB("bosq056"));
  AddExit("sur",ROOMFB("bosq073"));
  AnyadirPnjs();
  }
