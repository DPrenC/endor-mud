#include <living.h>
#include <properties.h>
#include "path.h"

inherit NPC;

#define P_COMIDO "##Comido##"
#define P_COMIDOP "##ComidoP##"
#define P_COMIDOF "##ComidoF##"

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
  string short, race;
  string ads, color;
  mixed *ataque, *chats, *chats_ataque;
  int nivel, tamanyo, genero, peso, size;
  int agresivo, achance;

  ::create();
  AddWalkZones("/d/lad-laurelin/comun/habitacion/tiinkdhil/bosque");

  tamanyo=random(3);
  color=random(2)?"pardo":"negro";

  SetStandard("un oso", "oso", 6+tamanyo*2, GENDER_MALE);
  SetShort("un oso"+(random(2)?" "+color:""));
  SetLong("Es un oso "+color+"; no parece hostil pero sería buena idea no "
  	"molestarlo.\n");
  switch(tamanyo) {
    case 0: SetLong(QueryLong()+"Este en cuestión "
    		"es bastante joven e inexperto, pero aún así imponente.\n");
    	    break;
    case 1: SetLong(QueryLong()+"Este oso ya es "
    		"adulto, aunque desde luego no es lo más grande que te "
    		"puedes encontrar.\n");
    	    break;
    case 2: SetLong(QueryLong()+"Este es un ejemplar "
    		"realmente impresionante, sencillamente enorme.\n");
    	    break;
  }
  SetWeight(160000+tamanyo*25000);
  SetHands(({({"zarpa derecha",0,7}),
  	({"zarpa izquierda",0,7}),
  	({"mandibulas",0,3})}));
  SetAggressive(tamanyo);
  SetAttackChance(50);
  AddId("oso");
  SetAds(({color, animal_size(tamanyo)}));
  SetWhimpy(QueryMaxHP()/4);
  InitChats(1, ({"Un oso "+color+" se rasca la espalda en un arbol.\n",
  		"Un oso "+color+" te mira.\n",
  		"Un oso "+color+" se encarama a un árbol.\n",
  		"Un oso "+color+" husmea el ambiente.\n",
  		"Un oso "+color+" se limpia el pelaje.\n"}));

  InitAChats(10, ({"Un oso "+color+" te gruñe.\n",
  		"Un oso "+color+" suelta un alarido impresionante.\n",
  		"Un oso "+color+" se eleva sobre sus patas traseras.\n"}));
  SetGoChance(25);
}


void comer_cadaver(object ob, int flag)
{
  object otromas;

  if (QueryFood()>=QueryMaxFood())
  {
    say(capitalize(QueryShort())+" parece haber saciado su apetito.\n");
    ob->SetDecay(1);
    ob->Set(P_COMIDO, 0);
    ob->Set(P_COMIDOP, 0);
    ob->Set(P_COMIDOF, 0);
    return;
  }
  if (Query(P_ENEMIES)!=({}))
    call_out("comer_cadaver", 4, ob, 1);
  if (flag<=0)
  {
    ob->SetDecay(0);
    ob->Set(P_COMIDOP, 0);
    say(capitalize(QueryShort())+" empieza a comerse "+ob->QueryShort()+".\n");
    call_out("comer_cadaver", 2, ob, 1);
    return;
  }
  else
  {
    AddFood(5);
    switch (random(3)) {
      case 0: switch(random(3)) {
                case 0: say(capitalize(QueryShort())+" le da un bocado a "+ob->QueryShort()+".\n");
      	  	        break;
                case 1: say(capitalize(QueryShort())+" mastica un poco de carne.\n");
      		        break;
                case 2: say(capitalize(QueryShort())+" le da una dentellada a "+ob->QueryShort()+".\n");
      	         	break;
      	      }
      	      break;
      default:break;
    }

    ob->Set(P_COMIDOP, ob->Query(P_COMIDOP)+10);
    if (ob->Query(P_COMIDOP)*10>ob->QueryWeight())
    {
      Set(P_COMIDOF, 0);
      say(capitalize(QueryShort())+
      	" se ha comido "+ob->QueryShort()+".\n");
      ob->remove();
      return;
    }
    call_out("comer_cadaver", 4, ob, 1);
  }
}

heart_beat()
{
  object *comida;
  int i;

  ::heart_beat();
  if (!environment()) return;
  comida=all_inventory(environment());

  for (i=0;i<sizeof(comida);i++)
    if (member(inherit_list(comida[i]), "std/corpse.c")!=-1)
      if (QueryFood()<QueryMaxFood() && comida[i]->Query(P_COMIDO)!=TO && !Query(P_COMIDO))
      {
        call_out("comer_cadaver", 1, comida[i], 0);
        Set(P_COMIDOF, object_name(comida[i]));
        Set(P_COMIDO, comida[i]);
        return;
      }

  //Algo ha pasado... se ha 'ido' el cuerpo y yo estaba comiendo...
  if (Query(P_COMIDOF) && (!find_object(Query(P_COMIDOF)) || (environment() != environment(find_object(Query(P_COMIDOF))))))
  {
    Set(P_COMIDO,0);
    Set(P_COMIDOF,0);
    Set(P_COMIDOP,0);
  }

  if (Query(P_COMIDOF))
    if (environment() != environment(find_object(Query(P_COMIDOF))))
    {
      Set(P_COMIDO,0);
      Set(P_COMIDOF,0);
      Set(P_COMIDOP,0);
    }

  GetHeart(HEART_USER);
}
