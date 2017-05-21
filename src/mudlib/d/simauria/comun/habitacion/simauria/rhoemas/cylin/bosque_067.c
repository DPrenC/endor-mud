/***************************************************************************************
 ARCHIVO:	bosque_067.c
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
 AddExit("sur",RHOEHAB("cylin/bosque_086"));
 AddExit("este",RHOEHAB("cylin/bosque_068"));
 AddExit("noroeste",RHOEHAB("cylin/bosque_049"));
 AddExit("sudeste",RHOEHAB("cylin/bosque_087"));
 fanimales();
}
