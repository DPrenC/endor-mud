/***************************************************************************************
 ARCHIVO:	bosque_186.c
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
 AddExit("sur",RHOEHAB("cylin/bosque_206"));
 AddExit("oeste",RHOEHAB("cylin/bosque_185"));
 AddExit("noroeste",RHOEHAB("cylin/bosque_165"));
 fanimales();
}