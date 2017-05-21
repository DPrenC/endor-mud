/***************************************************************************************
 ARCHIVO:	pasillo_06.c
 AUTOR:		[z] Zomax
 FECHA:		28-12-2001
 COMENTARIOS:	Pasillo este
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, planta baja, ala este");
  AddExit("sur",RHOEHAB("seri/piso00/este/pasillo_05"));
  AddExit("oeste",RHOEHAB("seri/piso00/este/pasillo_07"));
  AddItem(RHOEPNJ("seri/aprendiz"),REFRESH_DESTRUCT,1+random(2));
}
