/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq132.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("suroeste",ROOMFB("bosq137"));
  AddExit("nordeste",ROOMFB("bosq123"));
  AnyadirPnjs();
  }
