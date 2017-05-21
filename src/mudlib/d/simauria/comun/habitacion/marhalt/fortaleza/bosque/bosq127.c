/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq127.c
Creacion	 : 4-7-00 [Maler]
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("oeste",ROOMFB("bosq126"));
  AddExit("este",ROOMFB("bosq128"));
  AddExit("sur",ROOMFB("bosq134"));
  AnyadirPnjs();
  }
