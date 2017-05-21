/***************************************************************************************
 ARCHIVO:	pasillo_01.c
 AUTOR:		[z] Zomax
 FECHA:		28-12-2001
 COMENTARIOS:	Pasillo este
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, planta baja, ala este");
  AddExit("norte",RHOEHAB("seri/piso00/este/habitacion_04"));
  AddExit("este",RHOEHAB("seri/piso00/este/pasillo_02"));
  AddExit("oeste",RHOEHAB("seri/piso00/este/pasillo_00"));
  if (!random(2)) AddItem(RHOEPNJ("seri/aprendiz"),REFRESH_DESTRUCT,1+random(2));
}
