/* **********************************************************************
   *  DESCRIPCION  :sendero que une el bosque con Krigor
   *  FICHERO      : prado01.c
   *  MODIFICACION : Creacion [Chaos]
*/
#include "path.h"
inherit KRIGOR("prado");

create()
{
	::create();
	
	AddExit("este",KRIGOR("sendero02"));
	AddExit("puerta",KRIGOR("casa01"));
	
}