/***************************************************************************************
 ARCHIVO:	bosque_201.c
 AUTOR:		[z] Zomax
 FECHA:		14-11-2001
 COMENTARIOS:	Bosque Cylin, en Koek
 ***************************************************************************************/

#include "path.h"

inherit RHOESTD("bosque");

create () {
 ::create();

 SetLocate("Bosque de Cylin");
 SetIntShort("el bosque de Cylin");
 AddExit("noroeste",RHOEHAB("cylin/bosque_180"));
 AddExit("suroeste",RHOEHAB("cylin/bosque_220"));
 fanimales();
}