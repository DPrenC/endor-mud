/***************************************************************************************
 ARCHIVO:	pasillo_03.c
 AUTOR:		[z] Zomax
 FECHA:		27-12-2001
 COMENTARIOS:	Pasillo central
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, planta baja");
  AddExit("norte",RHOEHAB("seri/piso00/centro/pasillo_04"));
  AddExit("sur",RHOEHAB("seri/piso00/centro/pasillo_02"));
  AddExit("este",RHOEHAB("seri/piso00/centro/altare"));
  AddExit("oeste",RHOEHAB("seri/piso00/centro/altaro"));
  AddItem(RHOEPNJ("seri/aprendiz"),REFRESH_DESTRUCT,1);
}
