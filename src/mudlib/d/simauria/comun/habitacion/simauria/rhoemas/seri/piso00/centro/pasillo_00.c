/***************************************************************************************
 ARCHIVO:	pasillo_00.c
 AUTOR:		[z] Zomax
 FECHA:		27-12-2001
 COMENTARIOS:	Pasillo central
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, planta baja");
  AddDetail(({"entrada"}),"Desde aquí puedes ver, al sur, la entrada del templo.\n");
  AddExit("norte",RHOEHAB("seri/piso00/centro/pasillo_01"));
  AddExit("sur",RHOEHAB("seri/piso00/centro/entrada"));
  AddItem(RHOEPNJ("seri/aprendiz"),REFRESH_DESTRUCT,1);
}
