/*
DESCRIPCION  : bosque alrededor de la fortaleza de nandor
FICHERO      : bosq120.c
Creacion     : 4-7-00 [Maler]
Modificaci�n : 26-04-2003 [Zomax] A�ado un pnj gusanos para un quest.
*/

#include "./path.h"
inherit ROOMFB("bosque");

create(){
  ::create();
 AddExit("nordeste",ROOMFB("bosq111"));
  AnyadirPnjs();
  AddItem(RHOEVAR("koek/varios/gusanos_seda"),REFRESH_REMOVE,1);
  }
