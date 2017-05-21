/***************************************************************************************
 ARCHIVO:	bosque_271.c
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
 AddExit("nordeste",RHOEHAB("cylin/bosque_257"));
 AddExit("noroeste",RHOEHAB("cylin/bosque_255"));
 fanimales();
}