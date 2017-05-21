/***************************************************************************************
 ARCHIVO:	pasillo_02.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo central
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, primer piso");
  AddExit("norte",RHOEHAB("seri/piso01/centro/pasillo_03"));
  AddExit("sudeste",RHOEHAB("seri/piso01/este/pasillo_00"));
  AddExit("suroeste",RHOEHAB("seri/piso01/oeste/pasillo_00"));
  if (!random(2)) AddItem(RHOEPNJ("seri/discipulo"),REFRESH_DESTRUCT,1+random(2));
}
