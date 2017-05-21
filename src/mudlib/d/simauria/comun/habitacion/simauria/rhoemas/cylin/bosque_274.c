/***************************************************************************************
 ARCHIVO:	bosque_274.c
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
 AddExit("noroeste",RHOEHAB("cylin/bosque_258"));
 AddExit("suroeste",RHOEHAB("cylin/bosque_286"));
 fanimales();
}