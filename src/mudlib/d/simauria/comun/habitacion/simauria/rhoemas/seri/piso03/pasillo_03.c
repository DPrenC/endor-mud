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

  SetLocate("Seri-Solderteg, tercer piso");
  AddExit("norte",RHOEHAB("seri/piso03/pasillo_02"));
  AddExit("sur",RHOEHAB("seri/piso03/pasillo_04"));
}
