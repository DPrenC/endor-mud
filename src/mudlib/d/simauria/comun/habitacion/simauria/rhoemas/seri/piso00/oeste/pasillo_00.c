/***************************************************************************************
 ARCHIVO:	pasillo_00.c
 AUTOR:		[z] Zomax
 FECHA:		28-12-2001
 COMENTARIOS:	Pasillo oeste
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, planta baja, ala oeste");
  AddExit("norte",RHOEHAB("seri/piso00/oeste/habitacion_05"));
  AddExit("este",RHOEHAB("seri/piso00/centro/entrada"));
  AddExit("oeste",RHOEHAB("seri/piso00/oeste/pasillo_01"));
  AddItem(RHOEPNJ("seri/aprendiz"),REFRESH_DESTRUCT,1+random(2));
}
