/***************************************************************************************
 ARCHIVO:	pasillo_01.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo central
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, tercer piso");
  AddExit("norte",RHOEHAB("seri/piso03/escalerao"));
  AddExit("oeste",RHOEHAB("seri/piso03/pasillo_02"));
  AddExit("nordeste",RHOEHAB("seri/piso03/pasillo_00"));
}
