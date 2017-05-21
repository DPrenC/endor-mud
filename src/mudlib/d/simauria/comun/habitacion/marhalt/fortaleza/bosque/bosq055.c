/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq055.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq051"));
  AddExit("suroeste",ROOMFB("bosq061"));
  AddExit("noroeste",ROOMFB("bosq049"));
  AddExit("sudeste",ROOMFB("bosq063"));
  AnyadirPnjs();
  }
