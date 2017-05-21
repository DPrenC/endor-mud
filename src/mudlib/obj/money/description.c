/*SIMAURIA '/obj/money/description.c'
  ===================================

  19-05-97 Theuzifan, Traducido y adaptado.
*/

#include <money.h>
#include "/secure/wizlevels.h"

inherit "/std/thing/description";

protected mapping money = ([]);

//-----------------------------------------------------------------------------

string QueryVersion();

//-----------------------------------------------------------------------------

public mapping QueryMoney() { return (mapping) copy(money||([])); }

//-----------------------------------------------------------------------------

public mixed QueryAutoObject() {
  return (money && sizeof(m_indices(money)))?
    ({QueryVersion(), (mapping) copy(money)}):0;
}

public mixed SetAutoObject(mixed arr) {
    int oldval, new_version;

    oldval = QueryValue();
    if (pointerp(arr)) {
        if (sizeof(arr) > 1) {
            if(!mappingp(arr[1])) return 0;
            money = arr[1];
        }
    }
    else {
      new_version = 1;
      money = arr;
    }
    if(new_version && IS_LEARNER(TP))
      tell_object(TP, sprintf("Nueva version del dinero: %s\n",QueryVersion()));
    MONEYLOGGER->new_money("SetAutoObject",QueryValue()-oldval);
    return money;
}

//-----------------------------------------------------------------------------

/* Remains from the old money... */
public string valuestring(string type) {
  string str;

  return sprintf("%-24s- %5i Unidades",
         ((str = "moneda de")?
          str + " " + type:type) + " [" +
         ((str = MONEY_DEMON->QueryCoinTypes()[type,MONEY_SHORT])?
          str:type[0..1]) + "]",
                 MONEY_DEMON->QueryCoinValue(type));
}

public int QueryMoneyObject() { return 1; }

public int SetWeight(mixed arg) { return 0; }
/* The weight is calculated from the amount of coins, you can't set it! */

public varargs string QuerySmell(string what) {
    switch(QueryValue()) {
        case      0..100    : return "No huele mal.\n";
        case    101..1000   : return "No huele demasiado mal.\n";
        case   1001..10000  : return "Huele bastante mal.\n";
        case  10001..100000 : return "Empiezas a marearte.\n";
        case 100001..1000000: return "El tufo es insoportable.\n";
        default: 
    }
    return "Llena el aire con el terrible olor del capitalismo y con la "
           "endemoniada avaricia de la riqueza.\n";
}

public int SetValue(mixed arg)      { return 0; }
/* The value is determined by the variable money, so you can't set it */

public string SetShort(mixed arg)   { return 0; }
/* The short is determined by the carried money, so you can't set it */

public int QueryWeight() {
    return MONEY_DEMON->QueryMoneyWeight(money); // No lo copy xq confio en el
}

public int QueryValue() {
    return MONEY_DEMON->QueryMoneyValue(money); // No lo copy xq confio en el
}

/* returns the number of the coins */
public int QueryCoinNumber()    {
    return MONEY_DEMON->QueryCoinNumber(money); // No lo copy xq confio en el
}

public varargs string Smell(string what) {
    if(!sizeof(money)) return "No hueles nada.\n";
    if(   TP
       && environment() != TP
       && environment() != environment(TP)
       && lower_case(TP->QueryGuild()||"") != "ladron"
       && TP->QueryRace() != "enano")
        return "No hueles nada.\n";
    return QuerySmell();
}

public string QueryShort() {
  if(!sizeof(money = MONEY_DEMON->CleanMoney(money))) return 0;
  return (TP||PO)->QueryBrief()?
          MONEY_DEMON->QueryMoneyShort(money,
         (!TP || (TP == environment()))?0:
                       (TP->QueryInt()+3)):
          MONEY_DEMON->QueryMoneyString(money,
         (!TP || (TP == environment()))?0:
          (TP->QueryInt()+3));
}

public string QueryLong() {
  if (!sizeof(money = MONEY_DEMON->CleanMoney(money))) return 0;
  return MONEY_DEMON->QueryMoneyLong(money,(TP == environment())?0:
                     (TP->QueryInt()+3));
}
