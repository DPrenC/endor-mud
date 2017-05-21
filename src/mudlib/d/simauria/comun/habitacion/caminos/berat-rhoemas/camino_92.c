/***************************************************************************************
 ARCHIVO:	camino_92.c
 AUTOR:		[z] Zomax
 FECHA:		14-01-2002
 COMENTARIOS:	Camino Berat - Rhoemas
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("camino");

create () {
  ::create();

  AddExit("noroeste",RHOEHAB("koek/calles/cendaf_06"));
  AddExit("sureste",RHOECAM("camino_91"));
  if (!random(3))
  	AddItem(RHOEPNJ("koek/campos/ave"),REFRESH_DESTRUCT,1+random(2));
}
