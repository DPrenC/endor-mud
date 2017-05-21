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

  SetStandard("un ent", "ent", 15+tamanyo*2, GENDER_MALE);
  SetShort("un "+size(tamanyo)+" ent");
  SetLong("Es un "+size(tamanyo)+ " ent. "
  	"Mide unos "+(6+tamanyo)+" metros de alto y un par de metros de "
  	"ancho. Como todos los ents, es un árbol que realiza las tareas de "
  	"cuidado de otros árboles. También los protegen, y suelen ser "
  	"peligrosos.\n");
  SetWeight(220000+tamanyo*20000);
  SetHands(({({"una rama",1,14+tamanyo*2}),
    	({"una rama",1,14+tamanyo*2})}));
  SetAC(5+tamanyo);
  SetAggressive(1);
  SetAttackChance(50);
  SetSize(P_SIZE_MEDIUM);
  AddId("ent");
  SetAds(({size(tamanyo)}));
  AddDefence(DT_FIRE,-10);
  AddDefence(DT_ACID,10);
  AddDefence(DT_COLD,-5);
  AddDefence(DT_WATER,25);
}
