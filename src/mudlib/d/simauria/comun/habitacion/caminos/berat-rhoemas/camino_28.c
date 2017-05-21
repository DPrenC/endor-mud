/***************************************************************************************
 ARCHIVO:	camino_28.c
 AUTOR:		[z] Zomax
 FECHA:		14-01-2002
 COMENTARIOS:	Camino Berat - Rhoemas
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("camino");

create () {
  ::create();

  AddExit("este",RHOECAM("camino_29"));
  AddExit("oeste",RHOECAM("camino_27"));
  if (!random(3))
  	AddItem(RHOEPNJ("koek/campos/ave"),REFRESH_DESTRUCT,1+random(2));
}
