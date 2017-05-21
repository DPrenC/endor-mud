/***************************************************************************************
 ARCHIVO:	pasillo_09.c
 AUTOR:		[z] Zomax
 FECHA:		28-12-2001
 COMENTARIOS:	Pasillo este 09
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, planta baja, ala este");
  AddExit("norte",RHOEHAB("seri/piso00/centro/escalerae"));
  AddExit("sur",RHOEHAB("seri/piso00/este/habitacion_00"));
  AddExit("este",RHOEHAB("seri/piso00/este/pasillo_08"));
  AddExit("noroeste",RHOEHAB("seri/piso00/centro/pasillo_02"));
  AddExit("suroeste",RHOEHAB("seri/piso00/centro/pasillo_01"));
  AddItem(RHOEPNJ("seri/aprendiz"),REFRESH_DESTRUCT,1+random(2));
}
