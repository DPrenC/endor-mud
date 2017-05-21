/***************************************************************************************
 ARCHIVO:	pasillo_09.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo central
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, tercer piso");
  AddExit("norte",RHOEHAB("seri/piso03/pasillo_10"));
  AddExit("sur",RHOEHAB("seri/piso03/pasillo_08"));
}
