/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq131.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("oeste",ROOMFB("bosq130"));
  AddExit("nordeste",ROOMFB("bosq122"));
  AnyadirPnjs();
  }
