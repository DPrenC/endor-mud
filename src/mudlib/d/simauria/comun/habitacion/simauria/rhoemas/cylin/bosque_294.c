/***************************************************************************************
 ARCHIVO:	bosque_294.c
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
 AddExit("norte",RHOEHAB("cylin/bosque_284"));
 AddExit("este",RHOEHAB("cylin/bosque_295"));
 AddExit("noroeste",RHOEHAB("cylin/bosque_283"));
 fanimales();
}