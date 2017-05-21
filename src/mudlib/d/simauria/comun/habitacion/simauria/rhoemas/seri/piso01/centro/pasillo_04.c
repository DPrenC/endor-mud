/***************************************************************************************
 ARCHIVO:	pasillo_04.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo central
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, primer piso");
  AddExit("sur",RHOEHAB("seri/piso01/centro/pasillo_03"));
  AddExit("este",RHOEHAB("seri/piso01/centro/habitacion_01"));
  AddExit("oeste",RHOEHAB("seri/piso01/centro/habitacion_00"));
  if (!random(2)) AddItem(RHOEPNJ("seri/discipulo"),REFRESH_DESTRUCT,1+random(2));
}
