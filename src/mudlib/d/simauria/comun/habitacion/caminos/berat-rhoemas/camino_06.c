/***************************************************************************************
 ARCHIVO:	camino_00.c
 AUTOR:		[z] Zomax
 FECHA:		14-01-2002
 COMENTARIOS:	Camino Berat - Rhoemas
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("camino");

create () {
  ::create();

  AddExit("noreste",RHOECAM("camino_07"));
  AddExit("oeste",RHOECAM("camino_05"));
  if (!random(3))
  	AddItem(RHOEPNJ("koek/campos/ave"),REFRESH_DESTRUCT,1+random(2));
}
