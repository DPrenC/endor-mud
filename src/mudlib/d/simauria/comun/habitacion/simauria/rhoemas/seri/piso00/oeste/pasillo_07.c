/***************************************************************************************
 ARCHIVO:	pasillo_07.c
 AUTOR:		[z] Zomax
 FECHA:		28-12-2001
 COMENTARIOS:	Pasillo oeste
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, planta baja, ala oeste");
  AddExit("sur",RHOEHAB("seri/piso00/oeste/habitacion_00"));
  AddExit("este",RHOEHAB("seri/piso00/oeste/pasillo_08"));
  AddExit("oeste",RHOEHAB("seri/piso00/oeste/pasillo_06"));
  if (!random(2)) AddItem(RHOEPNJ("seri/aprendiz"),REFRESH_DESTRUCT,1+random(2));
}
