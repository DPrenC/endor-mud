/***************************************************************************************
 ARCHIVO:	bosque_217.c
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
 AddExit("este",RHOEHAB("cylin/bosque_218"));
 AddExit("nordeste",RHOEHAB("cylin/bosque_198"));
 AddExit("noroeste",RHOEHAB("cylin/bosque_196"));
 fanimales();
}