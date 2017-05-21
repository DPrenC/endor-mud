/***************************************************************************************
 ARCHIVO:	pasillo_04.c
 AUTOR:		[z] Zomax
 FECHA:		27-12-2001
 COMENTARIOS:	Pasillo central
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, planta baja");
  AddExit("norte",RHOEHAB("seri/piso00/centro/pasillo_05"));
  AddExit("sur",RHOEHAB("seri/piso00/centro/pasillo_03"));
  AddExit("este",RHOEHAB("seri/piso00/centro/biblioteca"));
  AddExit("oeste",RHOEHAB("seri/piso00/centro/armeria"));
  if (!random(2)) AddItem(RHOEPNJ("seri/aprendiz"),REFRESH_DESTRUCT,1);
}
