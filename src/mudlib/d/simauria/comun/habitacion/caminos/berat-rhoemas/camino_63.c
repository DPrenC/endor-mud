/***************************************************************************************
 ARCHIVO:	camino_63.c
 AUTOR:		[z] Zomax
 FECHA:		14-01-2002
 COMENTARIOS:	Camino Berat - Rhoemas
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("camino");

create () {
  ::create();

  AddExit("sureste",RHOECAM("camino_64"));
  AddExit("noroeste",RHOECAM("camino_62"));
  if (!random(3))
  	AddItem(RHOEPNJ("koek/campos/ave"),REFRESH_DESTRUCT,1+random(2));
}
