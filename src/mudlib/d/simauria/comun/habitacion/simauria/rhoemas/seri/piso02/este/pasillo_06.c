/***************************************************************************************
 ARCHIVO:	pasillo_06.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo este 00
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, segundo piso, ala este");
  AddExit("norte",RHOEHAB("seri/piso02/este/pasillo_07"));
  AddExit("oeste",RHOEHAB("seri/piso02/este/pasillo_05"));
  AddItem(RHOEPNJ("seri/maestro"),REFRESH_DESTRUCT,1);
}
