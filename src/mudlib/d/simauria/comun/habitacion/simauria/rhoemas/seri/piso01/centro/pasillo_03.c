/***************************************************************************************
 ARCHIVO:	pasillo_03.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo central
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, primer piso");
  AddExit("norte",RHOEHAB("seri/piso01/centro/pasillo_04"));
  AddExit("sur",RHOEHAB("seri/piso01/centro/pasillo_02"));
  AddExit("este",RHOEHAB("seri/piso01/centro/habitacion_03"));
  AddExit("oeste",RHOEHAB("seri/piso01/centro/habitacion_02"));
  AddItem(RHOEPNJ("seri/discipulo"),REFRESH_DESTRUCT,1+random(2));
}
