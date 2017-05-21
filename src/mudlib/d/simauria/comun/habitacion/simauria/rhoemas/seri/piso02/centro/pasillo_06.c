/***************************************************************************************
 ARCHIVO:	pasillo_06.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo central
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, segundo piso");
  AddExit("sur",RHOEHAB("seri/piso02/centro/pasillo_07"));
  AddExit("oeste",RHOEHAB("seri/piso02/centro/pasillo_05"));
  AddItem(RHOEPNJ("seri/maestro"),REFRESH_DESTRUCT,1);
}
