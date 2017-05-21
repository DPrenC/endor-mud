/***************************************************************************************
 ARCHIVO:	pasillo_01.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo oeste 00
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, segundo piso, ala oeste");
  AddExit("norte",RHOEHAB("seri/piso02/oeste/pasillo_00"));
  AddExit("sur",RHOEHAB("seri/piso02/oeste/pasillo_02"));
  AddExit("oeste",RHOEHAB("seri/piso02/oeste/habitacion_01"));
  if (!random(2)) AddItem(RHOEPNJ("seri/maestro"),REFRESH_DESTRUCT,1);
}
