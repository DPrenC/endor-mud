/***************************************************************************************
 ARCHIVO:	bosque_065.c
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
 AddExit("sur",RHOEHAB("cylin/bosque_084"));
 AddExit("oeste",RHOEHAB("cylin/bosque_064"));
 AddExit("nordeste",RHOEHAB("cylin/bosque_049"));
 AddExit("sudeste",RHOEHAB("cylin/bosque_085"));
 fanimales();
}
