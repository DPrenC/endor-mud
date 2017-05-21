/***************************************************************************************
 ARCHIVO:	wareder.c
 AUTOR:		[z] Zomax
 FECHA:		14-12-2001
 COMENTARIOS:	Wareder, el herbolario.
 MODIFICACIÓN:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Wareder el herbolario","humano",10,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Wareder");
  SetIds(({"humano","wareder","Wareder","herbolario"}));
  Set(P_CANT_LURE,1);
  SetShort("Wareder el herbolario");
  SetLong(W("Wareder es el herbolario del pueblo, un humano con mirada picaresca "
  	"que se dedica a vender hierbas de todo tipo.\n"));

  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Wareder te dice: Koek es un lugar estupendo para hacer negocios.\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Wareder te dice: Um... no trae nada bueno... aléjate de él.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W("Wareder te dice: El templo de Seri-Solderteg "
  	"es la residencia de los monjes, y donde se entrenan y rinden culto a su "
  	"Diosa.\n"),1);
  AddItem(RHOEARM("koek/varios/delantal"),REFRESH_REMOVE,SF(wearme));
}
