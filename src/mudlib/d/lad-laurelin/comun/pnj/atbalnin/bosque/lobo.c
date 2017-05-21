#include <living.h>
#include <properties.h>
#include "path.h"

#define P_COMIDO "##Comido##"
#define P_COMIDOP "##ComidoP##"
#define P_COMIDOF "##ComidoF##"
#define P_FOLLOWS "##FOLLOWS##"

string long, short, name;
object CanKill;
inherit NPC;

//Aparte de saber quién es amigo, aquí se tiene en cuenta quién es el líder
//del grupo, pudiendo llegar a luchar dos lobos por el control de la manada.
//Los líderes tienen una bonificación de +1 en los stats

int IsFriend(object victim)
{
  int i;

  if (CanKill == victim)
    return 0;
  else if (victim->QueryRace()==QueryRace())
    return 1;
  if (QuerySize()<victim->QuerySize())
    if (!QueryFollowers()) return 1;

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
  string color;
  int tamanyo;

  ::create();
  AddWalkZones("/d/lad-laurelin/comun/habitacion/atbalnin/bosque");
  tamanyo=random(3);
  color=random(2)?"marrón":"gris";

  SetStandard(name="un lobo", "lobo", 6+tamanyo, GENDER_MALE);
  SetShort(short="un lobo"+(random(2)?" "+color:""));
  SetLong(long="Es un lobo "+color+" de tamaño "
  	+animal_size(tamanyo)+". Te mira con mucha hambre y parece "
  	"dispuesto a atacarte a la menor ocasión.\n");
  SetWeight(25000+5000*tamanyo);
  SetHands(({({"zarpa derecha",0,3}),
  	   ({"zarpa izquierda",0,3}),
  	   ({"colmillos",0,4})}));
  SetAggressive(1);
  SetAttackChance(800);
  AddId("lobo");
  SetAds(({color, animal_size(tamanyo)}));
  SetWhimpy(QueryMaxHP()/8);
  InitChats(2, ({"Un lobo "+color+" gruñe entre dientes.\n",
  		"Un lobo "+color+" te mira amenazador.\n",
  		"Un lobo "+color+" husmea el aire.\n",
  		"Un lobo "+color+" empieza a limpiarse.\n",
  		"Un lobo "+color+" se rasca las pulgas.\n",
  		"Un lobo "+color+" huele un árbol.\n"}));
  InitAChats(10, ({"Un lobo "+color+" ladra.\n",
  		"Un lobo "+color+" aulla de rabia.\n"}));
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


varargs void Die(int silent)
{
  if (Query(P_FOLLOWERS)) Set(P_FOLLOWERS, 0);
  ::Die(silent);
}


int actualiza_niveles(object victim)
{
  if (QueryRace()==victim->QueryRace())
  {
    if (victim->QueryLevel()<QueryLevel())
    {
      if (sizeof(victim->Query(P_ENEMIES)) || sizeof(Query(P_ENEMIES))
      	|| victim->Query(P_FOLLOWS) || Query(P_FOLLOWS))
        return 1;
/*
      if (Query(P_FOLLOWS) && find_object(object_name(Query(P_FOLLOWS))))
      {
      	if(environment()==environment(Query(P_FOLLOWS)))
          return 1;
      }
*/
      AddFollower(victim);
      victim->Set(P_FOLLOWS, TO);
      SetShort("lobo líder");
      SetName("lobo líder");
      SetStrBonus(1);
      SetIntBonus(1);
      SetDexBonus(1);
      SetConBonus(1);
      SetLong("Este lobo es el líder de la manada. "
    		"Es el que guía a los demás en la caza y el que se queda con "
    		"la mayor parte de la comida. Estos animales no permiten la "
    		"intrusión de otros posibles líderes, lo que normalmente acaba "
    		"con una pelea; el vencedor es el nuevo líder, y el perdedor "
    		"es expulsado de la manada.\n");

    }
    else if (victim->QueryLevel()==QueryLevel())
    {
      if (sizeof(victim->Query(P_ENEMIES)) || sizeof(Query(P_ENEMIES)))
      {
        victim->Set(P_FOLLOWERS, 0);
        Set(P_FOLLOWERS, 0);
        return 1;
      }
      if (victim->Query(P_FOLLOWERS))
      {
        CanKill=victim;
        Kill(victim);
        return 0;
      }
    }
    else
    {
      SetStrBonus(0);
      SetIntBonus(0);
      SetDexBonus(0);
      SetConBonus(0);
      SetName(name);
      SetShort(short);
      SetLong(long);
      Set(P_FOLLOWERS, 0);
    }
    return 1;
  }
}

heart_beat()
{
  object *comida;
  int i;

  ::heart_beat();

  if (!environment()) return;
  comida=all_inventory(environment());
  CanKill=0;

  for (i=0;i<sizeof(comida);i++)
  {
    actualiza_niveles(comida[i]);
    if (member(inherit_list(comida[i]), "std/corpse.c")!=-1)
      if (QueryFood()<QueryMaxFood() && comida[i]->Query(P_COMIDO)!=TO && !Query(P_COMIDO))
      {
        call_out("comer_cadaver", 1, comida[i], 0);
        Set(P_COMIDOF, object_name(comida[i]));
        Set(P_COMIDO, comida[i]);
        return;
      }
    IsFriend(comida[i]);
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
