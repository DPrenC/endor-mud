/***************************************************************************************
 ARCHIVO:	pasillo_00.c
 AUTOR:		[z] Zomax
 FECHA:		28-12-2001
 COMENTARIOS:	Pasillo este 00
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, planta baja, ala este");
  AddDetail(({"entrada"}),"Desde aquí puedes ver, al oeste, la entrada del templo.\n");
  AddExit("norte",RHOEHAB("seri/piso00/este/habitacion_03"));
  AddExit("este",RHOEHAB("seri/piso00/este/pasillo_01"));
  AddExit("oeste",RHOEHAB("seri/piso00/centro/entrada"));
  AddItem(RHOEPNJ("seri/aprendiz"),REFRESH_DESTRUCT,1+random(2));
}
