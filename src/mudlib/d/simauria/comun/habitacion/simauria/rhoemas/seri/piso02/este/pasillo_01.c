/***************************************************************************************
 ARCHIVO:	pasillo_01.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo este 00
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, segundo piso, ala este");
  AddExit("norte",RHOEHAB("seri/piso02/este/pasillo_00"));
  AddExit("sur",RHOEHAB("seri/piso02/este/pasillo_02"));
  AddExit("este",RHOEHAB("seri/piso02/este/habitacion_01"));
  if (!random(2)) AddItem(RHOEPNJ("seri/maestro"),REFRESH_DESTRUCT,1);
}
