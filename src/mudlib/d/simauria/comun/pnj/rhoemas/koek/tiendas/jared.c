/***************************************************************************************
 ARCHIVO:	jared.c
 AUTOR:		[z] Zomax
 FECHA:		19-12-2001
 COMENTARIOS:	Jared, el carpintero.
 MODIFICACI�N:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>


inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Jared el carpintero","humano",12,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Jared");
  SetIds(({"humano","jared","Jared"}));
  Set(P_CANT_LURE,1);
  SetShort("Jared el carpintero");
  SetLong(W("Jared es el carpintero del pueblo. Es un verdadero artesano que se "
  	"puede decir que convierte en oro toda la madera que toca. El pueblo "
  	"entero est� repleto de obras suyas y, a pesar de la gran demanda, ning�n "
  	"otro carpintero a conseguido consolidar otra carpinter�a.\n"));

  AddQuestion(({"carpinteria","carpinter�a"}),W("Jared te dice: La carpinter�a es mi vida. Estoy "
  	"disponible para ella siempre.\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Jared te dice: �Te gusta? Me encanta mejorarlo con mi trabajo.\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Jared te dice: Um... no trae nada bueno... al�jate de �l.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W("Jared te dice: El templo de Seri-Solderteg "
  	"es la residencia de los monjes, y donde se entrenan y rinden culto a su "
  	"Diosa.\n"),1);
  AddItem(RHOEARM("koek/varios/delantal"),REFRESH_REMOVE,SF(wearme));
}
