/***************************************************************************************
 ARCHIVO:	bosque_020.c
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
 AddExit("sur",RHOEHAB("cylin/bosque_033"));
 AddExit("oeste",RHOEHAB("cylin/bosque_019"));
 AddExit("noroeste",RHOEHAB("cylin/bosque_008"));
 AddExit("sudeste",RHOEHAB("cylin/bosque_034"));
 fanimales();
}
