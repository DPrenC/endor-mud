/*   rata.c
     Creada por : Blackrider
     Fecha 30-10-97
	 Revisada por : Nemesis
	 22-Dic-1997
	 Nemesis te dice: Pero tio!!!! Tu sabes lo que has hecho???
	 Esto no es una rata! Es Super Raton! Como le pones resistencia
	 al corte de 35?? Eso significa que cada vez que le ataques con
	 un arma que corte y le des, se le descuentan 35 puntos al danyo
	 que le hagas... Pero que mala bestia eres, hombre!
	 Por no mencionar el AC de 6... eso es algo asi como el AC de
	 una coraza completa reforzada! Salvaje!
	 Y... como OSAS ponerle defensa magica??? Que quieres, que llegue
	 un novatillo del Gremio de Magos, le tire un hechizo y no le
	 haga nada? A una simple y vulgar rata??? Como te pasas.
*/

inherit NPC;

#include <living.h>
#include <combat.h>

create() {
  ::create();
 SetStandard("una rata","rata",1,GENDER_FEMALE);
  SetShort("una rata");
  SetLong("Es una rata que no tiene muy buen aspecto.\n");
  SetIds(({"rata"}));
  SetNoise("Oyes como la rata escarba en el suelo.\n");
  SetSmell("Huele a cloaca podrida.\n");
  SetWeight(1500);
  SetIds(({"rata"}));
  SetMaxHP(20);
  SetHP(20); // No tiene buen aspecto...
  SetAlign(0);
  SetHands(({({"un mordisco",0,1})}));
  InitChats(10,({"La rata escarba en el suelo buscando algo para roer.\n"}));
}