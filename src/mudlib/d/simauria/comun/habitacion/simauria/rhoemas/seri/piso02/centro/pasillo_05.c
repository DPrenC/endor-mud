/***************************************************************************************
 ARCHIVO:	pasillo_05.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo central
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, segundo piso");
  AddExit("este",RHOEHAB("seri/piso02/centro/pasillo_06"));
  AddExit("oeste",RHOEHAB("seri/piso02/centro/pasillo_04"));
  if (!random(2)) AddItem(RHOEPNJ("seri/maestro"),REFRESH_DESTRUCT,1);
}
