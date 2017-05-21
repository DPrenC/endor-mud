#include <living.h>
#include <properties.h>
#include "path.h"

int alimento;
string long;
string eating;
#define P_COMIDO "##Comido##"
#define P_COMIDOP "##ComidoP##"
#define P_COMIDOF "##ComidoF##"

inherit NPC;


create() {
  string color;

  ::create();
  AddWalkZones("/d/lad-laurelin/comun/habitacion/tiinkdhil/bosque");
  color=random(2)?"marrón":random(2)?"moteado":"negro";

  SetStandard("un jabalí", "jabalí", 5, GENDER_MALE);
  SetShort("un jabalí"+(random(2)?" "+color:""));
  SetLong("Es un jabalí "+color+". Suelen ser "
  	"animales bastante peligrosos, y desde luego éste no dudará en "
  	"atacarte si lo cree conveniente.\n");
  SetWeight(35000);
  SetHands(({({"colmillos",0,5})}));
  SetAggressive(1);
  SetAttackChance(50);
  SetSize(P_SIZE_MEDIUM);
  SetIds(({"jabali", "jabalí", "cerdo"}));
  SetAds(({color}));
  SetWhimpy(QueryMaxHP()/4);
  InitChats(10, ({"Un jabalí "+color+" husmea el suelo.\n",
  		"Un jabalí "+color+" se pone a masticar algo.\n",
  		"Un jabalí "+color+" va de un sitio a otro.\n",
  		"Un jabalí "+color+" empieza a correr... y se para en seco.\n"
  		}));
  InitAChats(15, ({"El jabalí "+color+" ruge de rabia.\n",
  		"Al jabalí se le eriza el pelo.\n"}));
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
