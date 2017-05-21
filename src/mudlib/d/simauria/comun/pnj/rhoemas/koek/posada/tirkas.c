/***************************************************************************************
 ARCHIVO:	tirkas.c
 AUTOR:		[z] Zomax
 FECHA:		26-12-2001
 COMENTARIOS:	Tirkas, el posadero.
 MODIFICACI�N:  20-04-2003 Ahora las respuestas solo se las da al player que pregunta.
 ***************************************************************************************/

#include "path.h"
#include <properties.h>

inherit NPC;
#include RHOEDANYO

create(){
  ::create();
  SetStandard("Tirkas el posadero","humano",10,GENERO_MASCULINO);
  SetWhimpy(0);
  SetAlign(250);
  SetAggressive(0);
  SetName("Tirkas");
  SetIds(({"humano","tirkas","Tirkas","posadero"}));
  Set(P_CANT_LURE,1);
  SetShort("Tirkas el posadero");
  SetLong(W("Tirkas es el posadero del pueblo. Regenta una posada en el lado este de "
  	"Koek, que ofrece varios servicios durante todo el d�a. Tiene una peque�a barba "
  	"casta�a y ojos del mismo color. Parece muy amable.\n"));
  AddSubDetail(({"barba"}),"Es muy peque�a, pero es una barba en toda regla.\n");
  AddSubDetail(({"ojo","ojos"}),"Tiene los ojos casta�os muy bonitos.\n");
  AddQuestion(({"posada"}),W("Tirkas te dice: Fund� la posada hace ya mucho tiempo al ver que los "
  	"peregrinos que ven�an a Koek no ten�an sitio donde dormir ni comer. La verdad "
  	"es que fue una buena perspectiva de negocio. Me va bien.\n"),1);
  AddQuestion(({"guardia","guardias","patrullero","patrulleros"}),W("Tirkas te dice: La guardia de "
  	"Koek, junto con los patrulleros, nos protegen de los indeseables.\n"),1);
  AddQuestion(({"koek","Koek","pueblo","Pueblo","pueblo de koek","pueblo de Koek","Pueblo de koek","Pueblo de Koek"}),W(
	"Tirkas te dice: Cuanto m�s crezca m�s trabajo tendr�, as� que espero que siga como hasta "
	"ahora.\n"),1);
  AddQuestion(({"cylin","Cylin","bosque","Bosque","bosque de cylin","Bosque de cylin","bosque de Cylin","Bosque de Cylin"}),W(
	"Tirkas te dice: M�s de uno de mis clientes ha desaparecido all�. Si quieres un consejo... "
	"pi�nsateo antes de ir.\n"),1);
  AddQuestion(({"templo","Templo","Seri-Solderteg"}),W(
	"Tirkas te dice: Yo no ser�a nada sin el templo. Mi negocio sobrevive gracias a �l. As� que te "
	"puedes imaginar que estoy absolutamente a favor del templo.\n"),1);
}
