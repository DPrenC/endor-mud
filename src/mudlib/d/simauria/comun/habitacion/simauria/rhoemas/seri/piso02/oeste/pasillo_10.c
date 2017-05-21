/***************************************************************************************
 ARCHIVO:	pasillo_10.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo oeste 00
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, segundo piso, ala oeste");
  AddExit("sur",RHOEHAB("seri/piso02/oeste/habitacion_00"));
  AddExit("este",RHOEHAB("seri/piso02/oeste/pasillo_11"));
  AddExit("oeste",RHOEHAB("seri/piso02/oeste/pasillo_09"));
  if (!random(2)) AddItem(RHOEPNJ("seri/maestro"),REFRESH_DESTRUCT,1);
}
