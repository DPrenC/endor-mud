/** SIMAURIA '/std/food.c'
 *  ======================
 */

inherit THING;

//------------------------------------------------------------------------------

#include <health.h>
#include <properties.h>
#include <search.h>
#include <config.h>
#include <messages.h>
#include <sounds.h>

#define KIND_FOOD  "food"
#define KIND_DRINK "drink"

//------------------------------------------------------------------------------

private int stuff, alc, soak, heal, do_heal;
private string kind;
private mixed msgs;
private int started;

//------------------------------------------------------------------------------

create()
{
  ::create();
  SetWeight(1);
  SetShort("una comida");
  SetIds(({KIND_FOOD}));
  SetLong("Una comida normal y corriente.\n");
  seteuid(getuid());
  "/obj/lib/register"->Register(TO, "FOODLIST");
}

init()
{
  ::init();
  add_action("consume","comer");
  add_action("consume","beber");
  add_action("consume","consumir");
}

//------------------------------------------------------------------------------

public string SetFoodKind(string str)
{
  if (member(({KIND_FOOD,KIND_DRINK}),str)==-1)
    return kind;
  RemoveId(kind||KIND_FOOD);
  AddId(str);
  return kind = str;
}
public string QueryFoodKind() { return kind; }

public void SetDrink() { SetFoodKind(KIND_DRINK); }
public void SetFood() { SetFoodKind(KIND_FOOD); }
public int QueryDrink() { return kind == KIND_DRINK; }
public int QueryFood() { return kind == KIND_FOOD||!kind; }

public mixed SetFoodMsgs(mixed ms)
// ms = string: message to the player
//      array(2): message to player/environment
//      array(3): message to player/environment(see)/environment(cantsee)
//      array(4): message to player(see)/player(cantsee)/
//                environment(see)/environment(cantsee)
// ms = closure: function called to either return the appropriate message
//               like the scheme above or handling the messages itself;
//               in this case the function has to return 0.
//               The function will be called with the player-object and
//               the calling object as argument.
// The strings will be passed through process_string. Some functions
// which may be called are predefined:
// Pl_Name, Pl_name, Pl_Pronoun, Pl_pronoun, Pl_Possessive, Pl_possessive,
// Pl_Objective, Pl_objective, Pl_Genetive, Pl_genetive
{
  return msgs = ms;
}


public int QueryStarted() { return started; }
public int SetStarted(int s) { return started=s; }

public mixed QueryFoodMsgs() { return msgs; }

public int SetFoodSoak(int n) { return soak = n; }
public int QueryFoodSoak() { return soak; }
public int SetFoodStuff(int n) { return stuff = n; }
public int QueryFoodStuff() { return stuff; }
public int SetFoodAlc(int n) { return alc = n; }
public int QueryFoodAlc() { return alc; }
public int SetFoodHeal(int n) { return heal = n; }
public int QueryFoodHeal() { return do_heal?heal:0; }
public int SetDoHeal(int to) { return do_heal=to; }
public int QueryDoHeal() { return do_heal; }

public int QueryValue()
{
  int min_value, value;
  value = (::QueryValue());
  min_value = MIN_FOOD_EVAL(soak,stuff,alc,heal,QueryWeight());
  SetValue(value = value<min_value?min_value:value?value:random(10)+1);
  return value;
}

//[Nyh] hago cosas (creo pormiltaje y todo lo q conlleva) [bonito palabro, que no? XD]
#define MIL	1000 //"sensibilidad del asunto" (os he dicho q tengo resaca?)
protected varargs int do_consume(string verb)
{
  int p_stuff,p_intox,p_soak,
      p_max_stuff,p_max_intox,p_max_soak,_hp,
      pormiltaje=MIL, i;
  string p_name,*ms,verb_exit;
  //mixed tmp;

  if (verb=="consumir") verb_exit = "consume";
  if (verb=="beber")    verb_exit = "bebe";
  if (verb=="comer")    verb_exit = "come";
  if (!verb) verb_exit = "consume";

  p_intox = (int)TP->QueryAlcohol();
  p_stuff = (int)TP->QueryFood();
  p_soak = (int)TP->QueryDrink();
  p_max_intox = (int)TP->QueryMaxAlcohol();
  p_max_stuff = (int)TP->QueryMaxFood();
  p_max_soak = (int)TP->QueryMaxDrink();
  p_name  = (string)TP->QueryName();

  //[Nyh] empiezo a crear XD
  if ((p_stuff+stuff)>p_max_stuff || (p_intox+alc)>p_max_intox || (p_soak+soak)> p_max_soak) {
    //la hemos jodido mayo con las flores...
    //el primer miembro del if es para evitar divisions by zero XD
    if (stuff && ((i=MIL*(p_max_stuff-p_stuff)/stuff)<pormiltaje)) pormiltaje = i;
    if (alc   && ((i=MIL*(p_max_intox-p_intox)/alc  )<pormiltaje)) pormiltaje = i;
    if (soak  && ((i=MIL*(p_max_soak -p_soak )/soak )<pormiltaje)) pormiltaje = i;
  }
//Ahora pormiltaje es el tanto por mil que vamos a consumir del alimento
//o mejor dicho, deberia serlo...
  if (p_stuff<p_max_stuff || p_intox<p_max_intox || p_soak < p_max_soak)
  {
    stuff -= TP->AddFood( stuff*pormiltaje/MIL);
    alc   -= TP->AddAlcohol(alc*pormiltaje/MIL);
    soak  -= TP->AddDrink( soak*pormiltaje/MIL);
    heal  -= TP->HealHP(   heal*pormiltaje/MIL);

    if (!QueryStarted()) {
    	SetStarted(1);
    	if (QueryFood()) {
		SetShort(QueryShort() + " a medio comer");
		SetLong(QueryLong() + "Está a medio comer");
	}
	else if (QueryDrink()) {
		SetShort(QueryShort() + " a medio beber");
		SetLong(QueryLong() + "Está a medio beber");
	}
    }
/*
  if (  (!stuff || p_stuff + stuff <= p_max_stuff)
      &&(!alc   || p_intox + alc   <= p_max_intox)
      &&(!soak  || p_soak  + soak  <= p_max_soak))
    {
      if (!call_resolved(&tmp, TP, "AddFood", stuff))
        TP->AddFood(stuff);
      if (!call_resolved(&tmp, TP, "AddAlcohol", alc))
        TP->drink_alcohol(alc);
      if (!call_resolved(&tmp, TP, "AddDrink", soak))
        TP->drink_soft(soak);
      if (!call_resolved(&tmp, TP, "Heal", heal))
        TP->heal_self(heal);
*/
   if (QueryFoodKind() == "food") play_sound(environment(TP), SND_SUCESOS("comer"));
   else play_sound(environment(TP), SND_SUCESOS("beber"));
   if (!msgs)
	{
	  write(capitalize(verb_exit)+"s "+QueryShort()+".\n");
	  tell_room(environment(TP), ({ MSG_SEE, p_name+" "+verb_exit+" "+QueryShort()+".\n"}), ({ TP }));
	}
      else
	{
	  if (closurep(msgs))
	    ms = funcall(msgs,TP,TO);
          else
            ms = msgs;
          if (stringp(ms))
          {
            write(ms);
            tell_room(environment(TP), ({ MSG_SEE, p_name+" "+verb_exit+" "+QueryShort()+".\n"}), ({ TP }));
          }
 	     else
       if (pointerp(ms))
	      {
	        switch(sizeof(ms))
		  {
		   case 0:
		    break;
		   case 1:
		    write(process_string(ms[0]));
      tell_room(environment(TP), ({ MSG_SEE, p_name+" "+verb_exit+" "+QueryShort()+".\n", "Escuchas como alguien come cerca de ti.\n"}), ({ TP }));
		    break;
		   case 2:
		    write(process_string(ms[0]));
		    say(process_string(ms[1]));
		    break;
		   case 3:
		    write(process_string(ms[0]));
		    tell_room(environment(TP), ({ MSG_SEE, process_string(ms[1]),process_string(ms[2])}), ({ TP }));
		    break;
		   default:
		    tell_object(TP, ({MSG_SEE,process_string(ms[0]),process_string(ms[1])}));
		    tell_room(environment(TP), ({ MSG_SEE, process_string(ms[2]),process_string(ms[3])}), ({ TP }));
		  }
	      }
	}
      if (QueryFood() && stuff<1) remove();
      if (QueryDrink() && soak<1) remove();
      else
      {
        if (stuff)
        {
          write("Das algunos desganados bocados hasta quedar totalmente saciado.\n");
          tell_room(environment(TP), ({ MSG_SEE, "Da algunos bocados hasta quedar totalmente saciado.\n"}), ({ TP }));
        }
        else if (soak || alc)
        {
          write("Pegas unos desganados sorbos hasta quedar totalmente saciado.\n");
          tell_room(environment(TP), ({ MSG_SEE, "Pega unos desganados sorbos pero no parece tener sed.\n"}), ({ TP }));
        }
      }
    }
  else
    if (p_intox + alc > p_max_intox)
      {
	write("Tu borrachera es tan épica que no te es posible ingerir ni una gota de alcohol más.\n");
        tell_room(environment(TP), ({ MSG_SEE, p_name+" carga con tal borrachera que le es imposible beber una gota más de alcohol.\n"}), ({ TP }));
      }
    else
      if (p_stuff + stuff > p_max_stuff)
        {
	  write("No puedes comer nada más.\n");
	  tell_room(environment(TP), ({ MSG_SEE, p_name+" no es capaz de comer nada más.\n"}), ({ TP }));
	}
      else
        if (p_soak + soak > p_max_soak)
	  {
	    write("No puedes tragar nada más, tu estómago está lleno de líquido.\n");
	    say(p_name+" tiene tanto líquido en su cuerpo que no puede tragar nada más...\n");
	  }
  return 1;
}

public int consume(string str)
{
  string verb;
  object *obs;

  if (!str)
    return notify_fail("¿"+capitalize(query_verb())+" qué?\n",
		       NOTIFY_NOT_OBJ),0;
  if (!foundp(TO,search(TP,str,SEARCH_INV|SM_OBJECT|SM_IGNLIGHT))
      ||(query_verb()=="beber"&&!QueryDrink())
      ||(query_verb()=="comer"&&!QueryFood()))
    return notify_fail("No encuentras ningún "+str+" que puedas "+query_verb()+".\n",
		       NOTIFY_NOT_OBJ),0;
  verb=query_verb();
  return do_consume(verb);
}

/*
* Functions to be used in process_string
*/

public string Pl_Name() { return capitalize(TP->QueryName()); }
public string Pl_name() { return TP->QueryName(); }
public string Pl_Pronoun() { return capitalize(TP->QueryPronoun()); }
public string Pl_pronoun() { return TP->QueryPronoun(); }
public string Pl_Possessive() { return capitalize(TP->QueryPossessive()); }
public string Pl_possessive() { return TP->QueryPossessive(); }
public string Pl_Objective() { return capitalize(TP->QueryObjective()); }
public string Pl_objective() { return TP->QueryObjective(); }
// [Nyh] No me he puesto a mirar si esto funciona, pero si que se que en
//       español no hay genitivos y se que la funcion add_gen ya no existe
//public string Pl_Genetive() { return capitalize(add_gen(TP->QueryName())); }
//public string Pl_genetive() { return add_gen(TP->QueryName()); }
public string Pl_Genetive() { return capitalize(TP->QueryName()); }
public string Pl_genetive() { return TP->QueryName(); }
