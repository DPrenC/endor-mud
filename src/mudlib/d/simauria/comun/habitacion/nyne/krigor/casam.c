/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : casam.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("casa");

create()
{
	::create();
	AddItem(PNJKRIG("maegrin"),REFRESH_DESTRUCT,1);
	AddExit("salir",KRIGOR("sendero13"));
	
}	
