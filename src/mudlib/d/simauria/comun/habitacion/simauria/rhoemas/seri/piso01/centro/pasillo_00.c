/***************************************************************************************
 ARCHIVO:	pasillo_00.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo central
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, primer piso");
  AddExit("sur",RHOEHAB("seri/piso01/centro/altar"));
  AddExit("este",RHOEHAB("seri/piso01/este/pasillo_02"));
  AddExit("oeste",RHOEHAB("seri/piso01/oeste/pasillo_02"));
  if (!random(2)) AddItem(RHOEPNJ("seri/discipulo"),REFRESH_DESTRUCT,1+random(2));
}
