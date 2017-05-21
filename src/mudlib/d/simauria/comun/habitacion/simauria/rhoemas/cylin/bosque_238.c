/***************************************************************************************
 ARCHIVO:	bosque_238.c
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
 AddExit("sur",RHOEHAB("cylin/bosque_255"));
 AddExit("este",RHOEHAB("cylin/bosque_239"));
 AddExit("suroeste",RHOEHAB("cylin/bosque_254"));
 fanimales();
}