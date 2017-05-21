/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq051.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq045"));
  AddExit("suroeste",ROOMFB("bosq055"));
  AddExit("sudeste",ROOMFB("bosq057"));
  AnyadirPnjs();
  }
