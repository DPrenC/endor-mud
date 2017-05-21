/***
Fichero: ent.c
Autor: (sin comentarios en el archivo)
Modificación: 21/12/2004 [kastwey@simauria].
Modifico que no ataque a todos, sino que solo a los enemigos de los elfos.
***/

#include <living.h>
#include <properties.h>
#include "path.h"

inherit NPC;

string size(int tam)
{
  switch(tam) {
    case 1: return "gran";
    case 2: return "enorme";
  }
  return "mediano";
}

create() {
  int tamanyo;

  ::create();

  tamanyo=random(3);

  SetStandard("un ent", "ent", 25+tamanyo*3, GENDER_MALE);
  SetShort("un "+size(tamanyo)+" ent");
  SetLong("Es un "+size(tamanyo)+ " ent. "
  	"Mide unos "+(6+tamanyo)+" metros de alto y un par de metros de "
  	"ancho. Como todos los ents, es un árbol que realiza las tareas de "
  	"cuidado de otros árboles. También los protegen, y suelen ser "
  	"peligrosos.\n");
  SetWeight(220000+tamanyo*20000);
  SetHands(({({"una rama",1,24+tamanyo*3}),
    	({"una rama",1,24+tamanyo*3})}));
  SetAC(10+tamanyo*3);
  // SetAggressive(1); // ahora solo ataca a las razas enemigas de los elfos
  SetAttackChance(1000);
  SetSize(P_SIZE_MEDIUM);
  AddId("ent");
  SetAds(({size(tamanyo)}));
  AddDefence(DT_FIRE,-10);
  AddDefence(DT_ACID,10);
  AddDefence(DT_COLD,-5);
  AddDefence(DT_WATER,25);
}

init()
{
	::init();
	// si es enemigo de los elfos ataca.
	if (member(RAZASENEMIGAS,TP->QueryRace()) > -1)
	// es enemigo
	{
		Kill(TP || PO);
  }
}
