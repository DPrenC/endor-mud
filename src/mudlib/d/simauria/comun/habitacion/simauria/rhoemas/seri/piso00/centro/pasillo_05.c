/***************************************************************************************
 ARCHIVO:	pasillo_05.c
 AUTOR:		[z] Zomax
 FECHA:		27-12-2001
 COMENTARIOS:	Pasillo central
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, planta baja");
  AddExit("norte",RHOEHAB("seri/piso00/centro/cylin"));
  AddExit("sur",RHOEHAB("seri/piso00/centro/pasillo_04"));
  AddItem(RHOEPNJ("seri/aprendiz"),REFRESH_DESTRUCT,1);
  AddItem(RHOEPNJ("seri/draego"),REFRESH_DESTRUCT,1);
}
