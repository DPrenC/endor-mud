/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq049.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq044"));
  AddExit("sudeste",ROOMFB("bosq055"));
  AnyadirPnjs();
  }
