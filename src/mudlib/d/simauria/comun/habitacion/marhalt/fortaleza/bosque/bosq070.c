/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq070.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq061"));
  AddExit("oeste",ROOMFB("bosq069"));
  AddExit("sur",ROOMFB("bosq080"));
  AddExit("sudeste",ROOMFB("bosq081"));
  AnyadirPnjs();
  }
