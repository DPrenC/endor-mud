/***************************************************************************************
 ARCHIVO:	camino_20.c
 AUTOR:		[z] Zomax
 FECHA:		14-01-2002
 COMENTARIOS:	Camino Berat - Rhoemas
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("camino");

create () {
  ::create();

  AddExit("este",RHOECAM("camino_21"));
  AddExit("suroeste",RHOECAM("camino_19"));
  if (!random(3))
  	AddItem(RHOEPNJ("koek/campos/ave"),REFRESH_DESTRUCT,1+random(2));
}