/***************************************************************************************
 ARCHIVO:	bosque_286.c
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
 AddExit("nordeste",RHOEHAB("cylin/bosque_274"));
 AddExit("suroeste",RHOEHAB("cylin/bosque_295"));
 fanimales();
}