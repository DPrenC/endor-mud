/***************************************************************************************
 ARCHIVO:	pasillo_11.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo central
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, tercer piso");
  AddExit("norte",RHOEHAB("seri/piso03/escalerae"));
  AddExit("este",RHOEHAB("seri/piso03/pasillo_10"));
  AddExit("noroeste",RHOEHAB("seri/piso03/pasillo_00"));
  
}
