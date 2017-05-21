/***************************************************************************************
 ARCHIVO:	pasillo_07.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo central
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, tercer piso");
  AddExit("norte",RHOEHAB("seri/piso03/altare"));
  AddExit("este",RHOEHAB("seri/piso03/pasillo_08"));
  AddExit("oeste",RHOEHAB("seri/piso03/pasillo_06"));
}
