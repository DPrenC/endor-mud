/***************************************************************************************
 ARCHIVO:	pasillo_02.c
 AUTOR:		[z] Zomax
 FECHA:		27-12-2001
 COMENTARIOS:	Pasillo central
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, planta baja");
  AddExit("norte",RHOEHAB("seri/piso00/centro/pasillo_03"));
  AddExit("sudeste",RHOEHAB("seri/piso00/este/pasillo_09"));
  AddExit("suroeste",RHOEHAB("seri/piso00/oeste/pasillo_09"));
  if (!random(2)) AddItem(RHOEPNJ("seri/aprendiz"),REFRESH_DESTRUCT,1);
}
