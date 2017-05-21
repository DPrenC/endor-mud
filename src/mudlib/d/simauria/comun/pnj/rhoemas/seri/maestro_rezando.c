/***************************************************************************************
 ARCHIVO:	maestro.c
 AUTOR:		[z] Zomax
 FECHA:		30-12-2001
 COMENTARIOS:	Un maestro del templo.
 MODIFICACION:	20-04-2003 Cambio radical para adaptarlo al nuevo combat. Ahora como
     				lanza hechizos es un spellmonster y los lanza de verdad.
		05-05-2003 Quitadas defensas.
		11-05-2003 Bajo niveles de Standard
		12-06-2003 Bajo HP al Standard
 		12-06-2003 [Nyh] Retoco muchas cosas
 ***************************************************************************************/

#include "path.h"

inherit RHOEPNJ("seri/maestro_base");

create(){
  ::create();
 InitChats(4,({"El maestro reza concentrado\n",
		"El maestro dice: ¡¿Qué haces en este lugar sagrado, infiel?!.\n",
		"El maestro dice: Oh Xaenetia, diosa de la protección, protégenos de las oscuras criaturas que nos acechan.\n"}));
}
