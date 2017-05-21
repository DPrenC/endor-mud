/***************************************************************************************
 ARCHIVO:	pasillo_04.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo oeste 00
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, segundo piso, ala oeste");
  AddExit("norte",RHOEHAB("seri/piso02/oeste/habitacion_03"));
  AddExit("este",RHOEHAB("seri/piso02/oeste/pasillo_03"));
  AddExit("oeste",RHOEHAB("seri/piso02/oeste/pasillo_05"));
  if (!random(2)) AddItem(RHOEPNJ("seri/maestro"),REFRESH_DESTRUCT,1);
}
