/**
 * SIMAURIA '/obj/money.c'
 */

#include <moving.h>
#include <money.h>
#include <properties.h>
#include "/secure/wizlevels.h"

#define VERSION "2.1b6cas"

static object too_much, new_env;

inherit "/std/base";
inherit "/std/thing/moving";
inherit "/obj/money/description";
inherit "/obj/money/smallfuns";

varargs object NewMoneyObject(mixed amnt, string type);

public int clean_up(int i) { return moving::clean_up(i); }

public void create() {
  ::create();
  if (!clonep()) return;
  seteuid(getuid());
  money = ([]);
  Set(P_NOBUY,1);
}

do_act() {
  return(mmm("actualizar"));
}

public void init() {
  add_action("do_help","ayuda");
  if(IS_LEARNER(TP)) {
    add_action("mmm","dinero");
    add_action("do_act","actualizar");
  }
}

public int remove() {
  money_rearrange(1);
  if(!TO) return 1;
  MONEYLOGGER->remove_money("remove",QueryValue());
  return ::remove();
}

int do_help(string str) {
  if(!str || (present(str) != TO)) return 0;

  if(str == "dinero" || str == MONEY_NAME) {
    write("Valores monetarios:\n" +
	  implode(map(sort_array(m_indices(IS_WIZARD(TP)?
						 MONEY_DEMON->QueryCoinTypes():
						 money)
				       ,SF(compare_value))
			    ,SF(valuestring)),"\n") + "\n");
    return 1;
  }
  notify_fail("Valores monetarios:\n" +
	      implode(map(sort_array(m_indices(IS_WIZARD(TP)?
						     MONEY_DEMON->
						     QueryCoinTypes():
						     money)
					   ,SF(compare_value))
				,SF(valuestring)),"\n") + "\n");
  return 0;
}

string QueryVersion() { return VERSION; }

/* Used in subid */

private void get_types(string type, mixed m_array) {
  if(m_array[1] <= 0) return;
  if(money[type] > m_array[1]) {
    m_array[0][type] = m_array[1];
    m_array[1] = 0;
  }
  else {
    m_array[0][type] = money[type];
    m_array[1] -= money[type];
  }
}

/* subid() gets the id of a single money type (without 'and' or ',') and tries
 * to parse it.
 */
public mapping subid(string str) {
  int    count = 0, i;
  string tmp, *types, *strs;
  mapping  m_map;

  if (!str || str == "") return ([]);
  str = implode(strs = explode(str," ")-({""})," ");

  tmp = 0;

  if(strs[0] == "todo") {
    tmp = str[5..];
    count = -1;
  }
  else if(strs[0] == "todos") { // Supongo q es "todos los algo"
    tmp = str[10..];
    count = -1;
  }
  else if(strs[0] == "todas") { // Supongo q es "todas las algo"
    tmp = str[10..];
    count = -1;
    /* Then we look if the string means all coins of a specified type */
  }
  else {
    count = atoi(strs[0]);
    if (!intp(count)) {
      count = -1;
      tmp = str;
    }
    else {
      if (count <= 0) return 0;
      if (sizeof(strs) > 1) tmp = implode(strs[1..], " ");
    }
    /* Last possibility: It means a specified amount */
  }
  // Count = la cantidad de monedas (-1 si son todas)
  // Tmp = el tipo de moneda que busco

  str = MONEY_DEMON->PresentMoney(tmp, money);

  if(!str) return 0;
  else {
    if(count > money[str]) return 0;
    m_map = ([str:(count == -1)?money[str]:count]);
  }

  m_map = MONEY_DEMON->CleanMoney(m_map);
  if (!sizeof(m_map)) return 0;

  return m_map;
}

/* The id() has to parse the given string and to split the money, if
 * necessary */
public int id(string str) {
  mapping m_array;
  //  object  new_money;

  if(!str) return 0;
//  printf("id->%s, %d\n", str);

  if(str == "dinero" || str == "monedas" || str == "moneda" || str == MONEY_NAME) {
    reunify_money();
    return 1;
  }

  /* Check, if there is money in the environment of the player.
   * So you use the money in the environment by default */
/*
   if(query_verb() != "drop" && TP == environment() &&
     environment(TP) &&
     (new_money = present(str,environment(TP))) &&
     new_money->id(str)) return 0;
 */
  // Parse the (remaining) money for the amount of coins demanded.
  if (QueryRemaining()) m_array = QueryRemaining()->subid(str);
  else m_array = subid(str);
  if (!m_array || !sizeof(m_array = MONEY_DEMON->CleanMoney(m_array)))
    return 0;

  if (QueryRemaining()) {
    walk_mapping(m_array, SF(subtract_from_remaining));
    AdjustMoney(m_array);
  }
  else {
    walk_mapping(money,SF(subtract_from_value),&m_array);
    if(m_array && sizeof(m_array)) SetRemaining(NewMoneyObject(m_array));
  }
  if(TP) TP->RegisterCmdFun("money_rearrange",0);
  else call_out("money_rearrange");
  SetMoveTo(environment());
  return 1;
}

/* This is the fun that does the whole work inside the money */
varargs int AdjustMoney2(string type, int amnt, int flag)
{
  int    wei;
  object oldenv;
  mixed  dummy;

  if((wei = MONEY_DEMON->QueryCoinWeight(type)) && environment()) {
    /* We have to take care about the moneyweight! */
    if(environment()->MayAddIntWeight(wei * amnt)) {
      environment()->AddIntWeight(wei * amnt);
    /* We can add it without problems, ok */
    }
    else {
      int small_amount;

      if(!(new_env = find_environment(oldenv = environment(),wei * amnt))) {
	    object *prev;
	    int i;

	    prev = ({});
	    while(previous_object(i)) prev += ({previous_object(i++)});
	    log_file(MONEY_ERRORLOG,
		    sprintf("--\n%s: Not enough room for money. Value: %d Command: %s\n"
                    "List of previous objects:\n%s\n",
    			    ctime(time()),
	    		    amnt * MONEY_DEMON->QueryCoinValue(type),
		    	    query_verb() || "",
			        implode(map(prev,SF(object_name)),"\n")));
	    return 0;
      } /* We don't find any environment we can put the money into.
	     * Log it as an error. */

      if(small_amount = get_max_number(wei)) {
	    amnt -= small_amount;
	    money[type] += small_amount;
	    environment()->AddIntWeight(small_amount * wei);
	    /* We add the amount of coins we can carry and correct the weight */
      }

      /* We try to find out the amount of coins we can still carry */
      if(!too_much) {
        /* Are we already saving the money? */
        too_much = clone_object(MONEY);
        too_much->AdjustMoney(money);
        environment()->AddIntWeight(-QueryWeight());
        money = ([type: amnt]);
        /* Save the current money in a new object and move the new one into
         * ourself */
      } else
        money[type] += amnt;
      /* We are already storing the old money, so just add the new */

      if(!flag) /* We aren't called by AdjustMoney() */
        move_too_much(&too_much, new_env, oldenv);
      /* We add the weight we just set by changing the money mapping */
      oldenv->AddIntWeight(wei * amnt);
      return 1;
    }
  }
  if((int)money[type] < -amnt) return 0;
  money[type] += amnt;
  if(!money[type]) money = m_delete(money,type); /* Erasing empty coins */

  MONEYLOGGER->new_money("AdjustMoney2",
			  amnt * MONEY_DEMON->QueryCoinValue(type));
  return 1;
}

/* [Nyh] Retoco esto ligeramente
Opciones:
AdjustMoney(mapping) -> a�ade ese dinero
AdjustMoney(pointer) -> a�ade ese dinero
AdjustMoney(int, string) -> a�ade int monedas del tipo string
AdjustMoney(int) -> a�ade int monedas de cobre de forma simplificada
*/
varargs int AdjustMoney(mixed amnt, string type) {
  if (!amnt && !type) return 0;
  /* Oops? No arguments? */

  if (intp(amnt) && !type) amnt = MONEY_DEMON->CreateMoney(amnt);

  if(mappingp(amnt)) {
    walk_mapping(amnt,SF(AdjustMoney2),1);
    if(too_much) move_too_much(&too_much, new_env, environment());
    return 1;
  }
  /* Ah! A moneymapping! */

  if(stringp(amnt) && intp(type))
    return AdjustMoney2((string)amnt, (int)type);
  /* algun capullo ha puesto los parametros al rev�s */

  if(!stringp(type)) return 0;
  /* No string? Sorry! */

  if(!amnt) return 1;
  /* No amount of coins? Ready! */

  return AdjustMoney2(type, amnt);
}

/* The "money <type> <amount>" could be a 'xalias' *shrug* */

public int mmm(string str)
{
  int    amnt;
  string type;

  if (!str)
  {
    return notify_fail(
        "** Utilizacion: dinero <tipo> <cantidad> para crear dinero.\n"
        "                actualizar dinero        para actualizar el dinero.\n");
  }

  if(environment() != TI) return 0;
  if(str == "actualizar") return update_money();
  if(2 != sscanf(str, "%s %d", type, amnt)) {
    return notify_fail(
        "** Utilizacion: dinero <tipo> <cantidad> para crear dinero.\n"
        "                actualizar dinero        para actualizar el dinero.\n");
  }
  if(!MONEY_DEMON->QueryCoinValue(type)) {
    return notify_fail("** Dinero sin valor.\n");
  }
  if(!amnt) {
    write("Ok.\n");
    return 1;
  }
  if(!AdjustMoney2(type, amnt)) {
    if(amnt < 0) return notify_fail("No tienes suficiente(s) " +
		              MONEY_DEMON->QueryMoneyString(([type:2]))[2..] + ".\n");
    return notify_fail("Han ocurrido cosas extranyas. Contacta con Theuzifan.\n");
  }
  write("Ok.\n");
  return 1;
}

/* Gets the difference between the given value and the stored value */
private int new_value(string type, mapping mon) {
  if(!stringp(type) || !mappingp(mon)) return 0;
  return mon[type] - money[type];
}
/* SetMoney() only for compatibility */
public int SetMoney(mapping newmoney) {
  MONEYLOGGER->remove_money("SetMoney",QueryValue());
  if (!mappingp(newmoney)) return 0;
  if (money) {
    AdjustMoney(map_indices(money, SF(new_value), newmoney));
    newmoney = map_indices(newmoney,SF(new_value), newmoney);
  }

  return AdjustMoney(newmoney);
}

/* NewMoneyObject() clones a new money object, adjusts its value and the value
 * of TO, and returns it. */
varargs object NewMoneyObject(mixed amnt, string type)
{
  object new;
  mixed  tmp;

  if(intp(amnt)) {
    if(amnt < 0) return 0;
    if(money[type] < amnt) return 0;
    money[type] -= amnt;
    if(environment())
      environment()->AddIntWeight(- MONEY_DEMON->QueryCoinWeight(type) * amnt);
  }
  else {
    if(!mappingp(amnt)) return 0;
    tmp = ({money + ([]),0});
    walk_mapping(amnt,SF(subtract_value),&tmp);
    if(tmp[1]) return 0;
    money = tmp[0];
    if(environment())
      environment()->AddIntWeight(- MONEY_DEMON->QueryMoneyWeight(amnt));
  }
  new = clone_object(MONEY);
  new->AdjustMoney(amnt, type);
  MONEYLOGGER->move_money("NewMoneyObject",new->QueryValue());
  return new;
}

/* The moving... maybe the most complicate thing in the moneyobject,
 * at least it causes several inconsistencies :) */

varargs int move(mixed dest, int method, mixed extra)
{
  int    res;
  object oldenv;

  oldenv = environment();
  if(TP) TP->RegisterCmdFun("money_rearrange",0);
  else call_out("money_rearrange",0);
  /* We try to let the player do the money_rearrange() call.
   * Otherwise we need an asynchronous call in some cases */

  if((res = ::move(dest, method, extra)) == ME_OK)
    MONEYLOGGER->move_money("move",QueryValue(),oldenv,environment());

  return res;
}
