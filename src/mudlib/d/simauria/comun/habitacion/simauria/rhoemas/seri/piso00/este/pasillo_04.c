/***************************************************************************************
 ARCHIVO:	pasillo_04.c
 AUTOR:		[z] Zomax
 FECHA:		28-12-2001
 COMENTARIOS:	Pasillo este
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, planta baja, ala este");
  AddExit("norte",RHOEHAB("seri/piso00/este/pasillo_05"));
  AddExit("sur",RHOEHAB("seri/piso00/este/pasillo_03"));
  if (!random(2)) AddItem(RHOEPNJ("seri/aprendiz"),REFRESH_DESTRUCT,1+random(2));
}
