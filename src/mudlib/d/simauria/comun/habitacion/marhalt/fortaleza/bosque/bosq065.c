/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq065.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("norte",ROOMFB("bosq058"));
  AddExit("nordeste",ROOMFB("bosq059"));
  AddExit("sur",ROOMFB("bosq074"));
  AnyadirPnjs();
  }
