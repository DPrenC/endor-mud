/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq022.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq017"));
  AnyadirPnjs();
  }
