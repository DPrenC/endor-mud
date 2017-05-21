/***************************************************************************************
 ARCHIVO:	pasillo_09.c
 AUTOR:		[z] Zomax
 FECHA:		13-01-2002
 COMENTARIOS:	Pasillo oeste 00
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("pasillo");

create () {
  ::create();

  SetLocate("Seri-Solderteg, segundo piso, ala oeste");
  AddExit("sur",RHOEHAB("seri/piso02/oeste/pasillo_08"));
  AddExit("este",RHOEHAB("seri/piso02/oeste/pasillo_10"));
  AddItem(RHOEPNJ("seri/maestro"),REFRESH_DESTRUCT,1);
}
