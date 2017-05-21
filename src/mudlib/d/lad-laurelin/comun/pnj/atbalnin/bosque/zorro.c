#include <living.h>
#include <properties.h>
#include "path.h"

inherit NPC;

int IsFriend(object victim)
{
  if (query_once_interactive(victim)) return 1;
  if (victim->QueryLevel()>=QueryLevel()) return 1;
  return 0;
}

string animal_size(int tamanyo)
{
  switch (tamanyo) {
    case 0: return "pequeño";
    case 1: return "mediano";
    case 2: return "grande";
  }
  return "medio";
}


create() {
  int tamanyo;

  ::create();

  AddWalkZones("/d/lad-laurelin/comun/habitacion/atbalnin/bosque");
  tamanyo=random(3);

  SetStandard("un zorro", "zorro", 3+tamanyo, GENDER_MALE);
  SetShort("un zorro"+(random(2)?" "+animal_size(tamanyo):""));
  SetLong("Es un zorro "+animal_size(tamanyo)+
  	". Parece mirar ansiosamente hacia más lugares de los que debiera. "
  	"Normalmente son animales bastante esquivos, aunque generalmente no "
  	"son peligrosos.\n");
  SetWeight(20000+tamanyo*2000);
  SetHands(({({"zarpa derecha",0,2}),
    	({"zarpa izquierda",0,2}),
    	({"hocico",0,3})}));
  SetAggressive(1);
  SetAttackChance(200);
  SetSize(P_SIZE_MEDIUM);
  AddId("zorro");
  SetAds(({animal_size(tamanyo)}));
  SetWhimpy(QueryMaxHP()/2);
  InitChats(5, ({"Un zorro "+animal_size(tamanyo)+" te mira cautamente.\n",
  		"Un zorro "+animal_size(tamanyo)+" husmea el aire.\n",
  		"Un zorro "+animal_size(tamanyo)+" se limpia las patas.\n",
  		"Un zorro "+animal_size(tamanyo)+" se rasca.\n",
  		"Un zorro "+animal_size(tamanyo)+" mastica algo.\n"}));
  SetGoChance(25);
}
