/***************************************************************************************
 ARCHIVO:	camino_38.c
 AUTOR:		[z] Zomax
 FECHA:		14-01-2002
 COMENTARIOS:	Camino Berat - Rhoemas
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("camino");

create () {
  ::create();

  AddExit("noreste",RHOECAM("camino_39"));
  AddExit("oeste",RHOECAM("camino_37"));
  if (!random(3))
  	AddItem(RHOEPNJ("koek/campos/ave"),REFRESH_DESTRUCT,1+random(2));
}
