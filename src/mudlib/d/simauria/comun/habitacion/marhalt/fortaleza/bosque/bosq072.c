/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq072.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq063"));
  AddExit("nordeste",ROOMFB("bosq064"));
  AddExit("sur",ROOMFB("bosq082"));
  AddExit("suroeste",ROOMFB("bosq081"));
  AnyadirPnjs();
  }
