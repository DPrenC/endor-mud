/***************************************************************************************
 ARCHIVO:	pasillo_00.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo oeste 00
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, segundo piso, ala oeste");
  AddExit("norte",RHOEHAB("seri/piso02/centro/escalerao"));
  AddExit("sur",RHOEHAB("seri/piso02/oeste/pasillo_01"));
  AddExit("oeste",RHOEHAB("seri/piso02/oeste/pasillo_11"));
  AddExit("nordeste",RHOEHAB("seri/piso02/centro/pasillo_02"));
  AddExit("sudeste",RHOEHAB("seri/piso02/centro/pasillo_01"));
  AddItem(RHOEPNJ("seri/maestro"),REFRESH_DESTRUCT,1);
}
