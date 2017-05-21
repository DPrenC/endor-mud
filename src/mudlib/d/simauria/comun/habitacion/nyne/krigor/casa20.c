/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : casa20.c
   *  CREACION     : [Chaos]
   * MODIFICACION  : 28-07-2002 [Bomber] Añado al puto guia de mierda.
*/
#include "path.h"
inherit KRIGOR("casa");

create()
{
	::create();

	AddItem(PNJKRIG("zeque"),REFRESH_DESTRUCT,1);
	AddExit("salir",KRIGOR("calle10"));
	
}	
