/***************************************************************************************
 ARCHIVO:	bosque_240.c
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
 AddExit("norte",RHOEHAB("cylin/bosque_221"));
 AddExit("nordeste",RHOEHAB("cylin/bosque_222"));
 AddExit("suroeste",RHOEHAB("cylin/bosque_256"));
 fanimales();
}