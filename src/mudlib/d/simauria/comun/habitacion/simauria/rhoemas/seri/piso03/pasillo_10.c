/***************************************************************************************
 ARCHIVO:	pasillo_10.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo central
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, tercer piso");
  AddExit("sur",RHOEHAB("seri/piso03/pasillo_09"));
  AddExit("oeste",RHOEHAB("seri/piso03/pasillo_11"));
  AddItem(RHOEPNJ("seri/maestro"),REFRESH_DESTRUCT,1);
}
