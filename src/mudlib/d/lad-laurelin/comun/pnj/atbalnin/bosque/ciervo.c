#include <living.h>
#include <properties.h>
#include "path.h"

inherit NPC;

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
  string color;
  int tamanyo;

  ::create();

  AddWalkZones("/d/lad-laurelin/comun/habitacion/atbalnin/bosque");
  tamanyo=random(3);
  color=random(2)?"marrón":"moteado";

  SetStandard("un ciervo", "ciervo", 3+tamanyo, GENDER_MALE);
  SetShort("un ciervo "+animal_size(tamanyo));
  SetLong("Es un ciervo "+animal_size(tamanyo)+".\n");

  switch(tamanyo)
  {
    case 0: SetLong(QueryLong()+"Es un animal "
      	            "bastante joven ya que su cornamenta no está todo lo "
      	            "desarrollada que puede llegar a estar.\n");
      	    break;
    case 1: SetLong(QueryLong()+"Aunque es un animal "
      	            "bastante tranquilo, su cornamenta impone, cuando menos, "
      	            "respeto.\n");
      	    break;
    case 2: SetLong(QueryLong()+"Este en concreto "
      	            "posee una inmensa cornamenta, la cual desde luego ha "
      	            "librado sus batallas.\n");
      	    break;
  }
  SetWeight(15000+tamanyo*5000);
  SetHands(({({"cornamenta",0,4})}));
  SetSize(P_SIZE_MEDIUM);
  AddId("ciervo");
  SetAds(({color, animal_size(tamanyo)}));
  SetWhimpy(QueryMaxHP()/2);
  InitChats(7, ({"Un ciervo "+animal_size(tamanyo)+" se pone a comer hierba.\n",
  		 "Un ciervo "+animal_size(tamanyo)+" te mira con indiferencia.\n",
  		 "Un ciervo "+animal_size(tamanyo)+" trota un poco dando vueltas.\n",
  		 "Un ciervo "+animal_size(tamanyo)+" espanta unos insectos con la cola.\n",
  		 "Un ciervo "+animal_size(tamanyo)+" husmea el ambiente.\n"}));
  SetGoChance(25);
}
