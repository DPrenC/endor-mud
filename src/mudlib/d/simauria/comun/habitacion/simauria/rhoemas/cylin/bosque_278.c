/***************************************************************************************
 ARCHIVO:	bosque_278.c
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
 AddExit("oeste",RHOEHAB("cylin/bosque_277"));
 AddExit("noroeste",RHOEHAB("cylin/bosque_264"));
 AddExit("sudeste",RHOEHAB("cylin/bosque_289"));
 fanimales();
}