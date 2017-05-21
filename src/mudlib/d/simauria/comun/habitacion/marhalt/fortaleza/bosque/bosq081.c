/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq081.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq070"));
  AddExit("nordeste",ROOMFB("bosq072"));
  AddExit("suroeste",ROOMFB("bosq092"));
  AddExit("sur",ROOMFB("bosq093"));
  AnyadirPnjs();
  }
