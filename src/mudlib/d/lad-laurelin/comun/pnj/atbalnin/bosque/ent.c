/***
Fichero: ent.c
Autor... (no tenía comentarios).
Modificación: kastwey@simauria.
21/12/2004: Reescribo muchas cosillas. Hago que solo ataque a los enemigos de
los elfos en faeria, que si no, no hay quien entre.
***/

#include <living.h>
#include <properties.h>
#include "path.h"

inherit NPC;

string size(int tam)
{
  switch(tam) {
    case 1: return "grande";
    case 2: return "enorme";
  }
  return "mediano";
}

create() {
  int tamanyo;

  ::create();

  tamanyo=random(3);

  SetStandard("un ent", "ent", 15+tamanyo*2, GENDER_MALE);
  SetShort("un ent " + size(tamanyo));
  SetLong("Es un ent de tamaño "+size(tamanyo)+ ". "
  	"Mide unos "+(6+tamanyo)+" metros de alto y un par de metros de "
  	"ancho. Como todos los ents, es un árbol que realiza las tareas de "
  	"cuidado de otros árboles. También los protegen, y suelen ser "
  	"peligrosos.\n");
  SetWeight(220000+tamanyo*20000);
  SetHands(({({"una rama",1,14+tamanyo*2}),
    	({"una rama",1,14+tamanyo*2})}));
  SetAC(5+tamanyo);
  // SetAggressive(1);
  SetAttackChance(50);
  SetSize(P_SIZE_MEDIUM);
  SetIds(({"ent", "ent " + size(tamanyo)}));
//  SetAds(({size(tamanyo)}));
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
