/***************************************************************************************
 ARCHIVO:	pasillo_09.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo este 00
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, primer piso, ala este");
  AddExit("sur",RHOEHAB("seri/piso01/este/pasillo_08"));
  AddExit("oeste",RHOEHAB("seri/piso01/este/pasillo_10"));
  AddItem(RHOEPNJ("seri/discipulo"),REFRESH_DESTRUCT,1+random(2));
}
