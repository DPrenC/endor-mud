/***************************************************************************************
 ARCHIVO:	pasillo_05.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo oeste 00
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, segundo piso, ala oeste");
  AddExit("este",RHOEHAB("seri/piso02/oeste/pasillo_04"));
  AddExit("oeste",RHOEHAB("seri/piso02/oeste/pasillo_06"));
  if (!random(2)) AddItem(RHOEPNJ("seri/maestro"),REFRESH_DESTRUCT,1);
}
