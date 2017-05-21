/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq080.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("noroeste",ROOMFB("bosq069"));
  AddExit("norte",ROOMFB("bosq070"));
  AddExit("nordeste",ROOMFB("bosq071"));
  AddExit("sudeste",ROOMFB("bosq093"));
  AnyadirPnjs();
  }
