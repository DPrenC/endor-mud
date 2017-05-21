/***************************************************************************************
 ARCHIVO:	pasillo_01.c
 AUTOR:		[z] Zomax
 FECHA:		27-12-2001
 COMENTARIOS:	Pasillo central
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, planta baja");
  AddExit("nordeste",RHOEHAB("seri/piso00/este/pasillo_09"));
  AddExit("noroeste",RHOEHAB("seri/piso00/oeste/pasillo_09"));
  AddExit("sur",RHOEHAB("seri/piso00/centro/pasillo_00"));
  if (!random(2)) AddItem(RHOEPNJ("seri/aprendiz"),REFRESH_DESTRUCT,1);
}
