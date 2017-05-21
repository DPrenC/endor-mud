/***************************************************************************************
 ARCHIVO:	pasillo_00.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo central
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, tercer piso");
  AddExit("sudeste",RHOEHAB("seri/piso03/pasillo_11"));
  AddExit("suroeste",RHOEHAB("seri/piso03/pasillo_01"));
  AddItem(RHOEPNJ("seri/maestro"),REFRESH_DESTRUCT,1);
}
