/***************************************************************************************
 ARCHIVO:	pasillo_02.c
 AUTOR:		[z] Zomax
 FECHA:		28-12-2001
 COMENTARIOS:	Pasillo oeste
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, planta baja, ala oeste");
  AddExit("norte",RHOEHAB("seri/piso00/oeste/habitacion_03"));
  AddExit("este",RHOEHAB("seri/piso00/oeste/pasillo_01"));
  AddExit("oeste",RHOEHAB("seri/piso00/oeste/pasillo_03"));
  if (!random(2)) AddItem(RHOEPNJ("seri/aprendiz"),REFRESH_DESTRUCT,1+random(2));
}
