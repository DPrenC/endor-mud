/***************************************************************************************
 ARCHIVO:	bosque_152.c
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
 AddExit("este",RHOEHAB("cylin/bosque_153"));
 AddExit("oeste",RHOEHAB("cylin/bosque_151"));
 AddExit("nordeste",RHOEHAB("cylin/bosque_133"));
 fanimales();
}