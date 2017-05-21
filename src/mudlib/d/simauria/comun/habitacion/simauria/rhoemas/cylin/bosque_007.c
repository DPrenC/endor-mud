/***************************************************************************************
 ARCHIVO:	bosque_007.c
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
 AddExit("oeste",RHOEHAB("cylin/bosque_006"));
 AddExit("sudeste",RHOEHAB("cylin/bosque_019"));
 fanimales();
}
