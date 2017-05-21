/***************************************************************************************
 ARCHIVO:	pasillo_01.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo central
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, segundo piso");
  AddExit("sur",RHOEHAB("seri/piso02/centro/altars"));
  AddExit("nordeste",RHOEHAB("seri/piso02/este/pasillo_00"));
  AddExit("noroeste",RHOEHAB("seri/piso02/oeste/pasillo_00"));
  AddItem(RHOEPNJ("seri/maestro"),REFRESH_DESTRUCT,2);
}
