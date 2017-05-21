/***************************************************************************************
 ARCHIVO:	bosque_276.c
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
 AddExit("noroeste",RHOEHAB("cylin/bosque_262"));
 AddExit("sudeste",RHOEHAB("cylin/bosque_287"));
 fanimales();
}