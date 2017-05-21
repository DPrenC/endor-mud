/***************************************************************************************
 ARCHIVO:	pasillo_06.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo oeste 00
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, primer piso, ala oeste");
  AddExit("norte",RHOEHAB("seri/piso01/oeste/pasillo_07"));
  AddExit("este",RHOEHAB("seri/piso01/oeste/pasillo_05"));
  AddItem(RHOEPNJ("seri/discipulo"),REFRESH_DESTRUCT,1+random(2));
}
