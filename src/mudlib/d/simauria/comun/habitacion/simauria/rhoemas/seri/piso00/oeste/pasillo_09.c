/***************************************************************************************
 ARCHIVO:	pasillo_09.c
 AUTOR:		[z] Zomax
 FECHA:		28-12-2001
 COMENTARIOS:	Pasillo oeste
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, planta baja, ala oeste");
  AddExit("norte",RHOEHAB("seri/piso00/centro/escalerao"));
  AddExit("sur",RHOEHAB("seri/piso00/oeste/habitacion_02"));
  AddExit("oeste",RHOEHAB("seri/piso00/oeste/pasillo_08"));
  AddExit("nordeste",RHOEHAB("seri/piso00/centro/pasillo_02"));
  AddExit("sudeste",RHOEHAB("seri/piso00/centro/pasillo_01"));
  AddItem(RHOEPNJ("seri/aprendiz"),REFRESH_DESTRUCT,1+random(2));
}
