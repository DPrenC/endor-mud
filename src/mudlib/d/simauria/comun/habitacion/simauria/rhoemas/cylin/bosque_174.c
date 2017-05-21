/***************************************************************************************
 ARCHIVO:	bosque_174.c
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
 AddExit("sur",RHOEHAB("cylin/bosque_194"));
 AddExit("este",RHOEHAB("cylin/bosque_175"));
 AddExit("oeste",RHOEHAB("cylin/bosque_173"));
 AddExit("noroeste",RHOEHAB("cylin/bosque_154"));
 fanimales();
}