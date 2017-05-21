/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : prado03.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("prado");

create()
{
	::create();
	
	AddExit("nordeste",KRIGOR("sendero03"));
	AddExit("noroeste",KRIGOR("manantial1"));
	AddExit("puerta",KRIGOR("casa03"));
	
}