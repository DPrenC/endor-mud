/***************************************************************************************
 ARCHIVO:	gato.c
 AUTOR:		[z] Zomax
 FECHA:		27-01-2002
 COMENTARIOS:	Un gato para el poblado de Flenton.
 ***************************************************************************************/

#include "path.h"
#include <moving.h>
#include <properties.h>
#include <sounds.h>
inherit NPC;

create(){
  ::create();
  SetStandard("un gato","gato",1+random(5),GENERO_MASCULINO);
  SetHands(({({"pata derecha",1,1}),({"pata izquierda",1,1})}));
  SetIds(({"gato"}));
  SetAlign(50);
  SetWhimpy(5);
  SetGoChance(10);
  SetWeight(2000);

  SetShort("un gato");
  SetLong("Es un bonito gato de pelo rojizo que corretea por la aldea sin ningún miedo.\n");

  InitChats(5,({"El gato te mira con curiosidad.\n",
   		"El gato se te acerca... ¡parece que le gustas!.\n",
   		"El gato olisquea el ambiente en busca de comida.\n",
        (:if (environment()) play_sound(environment(), SND_PNJS("gato")); return "El gato dice: ¿¡Miau!?\n";:),
   		"El gato se pone a perseguir las sombras de todo lo que encuentra.\n"}));
}


move(dest,method,stuff)
{
	if(method==M_GO && environment() && environment()->QueryLocate()!=dest->QueryLocate())
		return ME_NO_ENTER;
	return:: move(dest,method,stuff);
}
