#include "path.h"
#include <skills.h>

inherit ATB_CI("std_ciudad");

int cmd_bajar()
{
  int perc;

  write(W("Empiezas a bajar por la cuerda mientras dejas vagar tu mente por "
  	"lugares insondables... un pensamiento que te llega claramente es por "
  	"qué has decidido bajar por esa cuerda.\n"));
  perc=TP->UseSkill(HAB_TREPAR);

  if (perc<=0)
  {
    write(W("Ocurre lo inevitable cuando alguien con escasa habilidad intenta "
    	"deslizarse por una cuerda... caes y caes y piensas que el suelo está "
    	"más lejos de lo que podía parecer al principio. Probablemente será "
    	"cierto.\n"));
    TP->Defend(random(-(perc/2)));
  }

  write(W("¿Quien dice que los milagros no existen? Consigues bajar hasta el "
  	"suelo prácticamente ileso.\n"));
  TP->move(ATB_CI("ciudad00"));

  return 1;
}

create()
{
  ::create();
  SetIntLong(W("Intentas confeccionar mentalmente una lista de las posibles "
  	"razones que te han podido impulsar a llegar hasta donde estás, a "
  	"una cabaña situada alrededor de cinco metros del suelo. No es una "
  	"distancia larga para ser atravesada en horizontal, pero las cosas "
  	"cambian cuando se pasa a la vertical.\n"));
  AddDetail(({"cabaña", "cabanya"}), W("Es una cabaña situada en lo alto de "
  	"la copa del árbol, a la cual se llega por una fina cuerda sujeta "
  	"precariamente a una rama. Quien viva dentro probablemente no recibirá "
  	"demasiadas visitas.\n"));
  AddExit("bajar", SF(cmd_bajar));
  AddExit("entrar", ATB_TI("herreria01"));
}

