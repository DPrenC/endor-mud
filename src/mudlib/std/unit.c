/** SIMAURIA '/std/unit.c'
  * ======================
  */

#include <moving.h>
#include <classes.h>
#include <properties.h>

inherit THING;

//--- global variables ------------------------------------------------------

private string *pPids;
private int pAmount, pValuePU, pBrightPU, pWeightPU;
private mixed pPluralLong, pPluralShort;

private nosave int pLastAmount;
private nosave int pLastTime;
private nosave object pLastPlayer;

//---------------------------------------------------------------------------

public void create()
{
  ::create();
  pLastTime = time()-2;
  seteuid(getuid());
  AddClassAdj(CA_SPLITABLE);
}

//--- query and set functions for the properties ----------------------------

public int QueryBrightPerUnit(); // forward
public int QueryValuePerUnit();  // forward
public int QueryWeightPerUnit(); // forward

public int QueryAmount() { return pAmount; }
public int SetAmount(int a)
{
  int expected;
  expected = a * QueryWeightPerUnit();
  if (expected == (::SetWeight(expected)))
    {
      (::SetValue(a * QueryValuePerUnit()));
      (::SetBright(a * QueryBrightPerUnit()));
      return pAmount = a;
    }
}

public int QueryValuePerUnit() { return pValuePU; }
public int SetValuePerUnit(int v)
{
  (::SetValue(QueryAmount() * v));
  return pValuePU = v;
}

public int QueryBrightPerUnit() { return pBrightPU; }
public int SetBrightPerUnit(int v)
{
  (::SetBright(QueryAmount() * v));
  return pBrightPU = v;
}

public int QueryWeightPerUnit()    { return pWeightPU; }
public int SetWeightPerUnit(int w)
{
  int expected;
  expected = QueryAmount() * w;
  if (expected == (::SetWeight(expected)))
    {
      pWeightPU = w;
      return 1;
    }
}

public mixed QueryPluralShort()      { return pPluralShort; }
public mixed SetPluralShort(mixed s) { return pPluralShort = s; }

public varargs mixed QueryPluralLong(string what) { return pPluralLong; }
public mixed SetPluralLong(mixed l) { return pPluralLong = l; }

public int QueryLastAmount()    { return pLastAmount; }
public int SetLastAmount(int i) { return pLastAmount = i; }

//--- light and weight redefinition of a unit object ------------------------

public int SetLight(int l)
{
  SetBrightPerUnit((l - QueryLight()) / (QueryAmount() || 1));
  return QueryLight();
}

public int QueryLight()
{
  int amount;
  if (!QueryLastId())
    SetLastAmount(QueryAmount());
  return QueryBrightPerUnit()*QueryLastAmount();
}

public int SetBright(int l)
{
  SetBrightPerUnit(l / (QueryAmount() || 1));
  return QueryBright();
}

public int QueryBright()
{
  int amount;
  if (!QueryLastId())
    SetLastAmount(QueryAmount());
  return QueryBrightPerUnit()*QueryLastAmount();
}

public int SetWeight(int w)
{
  int amount;
  amount = QueryAmount() || 1;
  return amount * SetWeightPerUnit(w / amount);
}

public int QueryWeight()
{
  int amount;
  if (!QueryLastId())
    SetLastAmount(QueryAmount());
  return QueryWeightPerUnit()*QueryLastAmount();
}

public int SetValue(int v)
{
  int amount;
  amount = QueryAmount() || 1;
  return amount * SetValuePerUnit(v / amount);
}

public int QueryValue()
{
  int amount;
  if (!QueryLastId())
    SetLastAmount(QueryAmount());
  return QueryValuePerUnit()*QueryLastAmount();
}

//--- testing if we are equal to a specific unit ----------------------------

public int IsEqualUnit(int vpu, int bpu, int wpu, string psh, string sh,
                       string plg,string lg)
{
  return (   vpu == QueryValuePerUnit()
          && bpu == QueryBrightPerUnit()
          && wpu == QueryWeightPerUnit()
          && psh == QueryPluralShort()
          && sh == QueryShort()
          && plg == QueryPluralLong()
          && lg == QueryLong()
         );
}

public int IsEqualTo(object ob)
{
  return (   ob->QueryValuePerUnit() == QueryValuePerUnit()
          && ob->QueryBrightPerUnit() == QueryBrightPerUnit()
          && ob->QueryWeightPerUnit() == QueryWeightPerUnit()
          && ob->QueryPluralShort() == QueryPluralShort()
          && ob->QueryShort() == QueryShort()
          && ob->QueryPluralLong() == QueryPluralLong()
          && ob->QueryLong() == QueryLong()
         );
}

//--- id handling for units -------------------------------------------------

public string *QueryPluralIds() { return pPids; }
public string *SetPluralIds(string *ids)
{
  return pPids = sizeof(ids) ? map(ids, SF(norm_id)) : 0;
}
public string *AddPluralId(mixed str) { return pPids = _add_id(pPids, str); }
public string *RemovePluralId(mixed str){ return pPids = _del_id(pPids, str); }

public int id(string str)
{
  int a, last, diff;
  string *s;
  if (   time() > pLastTime
      || TP != pLastPlayer
     )
    {
      pLastTime = time();
      pLastPlayer = TP;
      SetLastAmount(0);
      last = 0;
    }
  else
    last = QueryLastAmount();
  diff = QueryAmount()-last;
  if (::id(str))
  // If the unit identifies to the string as /std/thing only one
  // item of the unit is meant.
    {
      SetLastAmount(last+1);
      // We need to raise the amount if someone wants to identify
      // the unit with 'thing, thing and thing' where 'thing' is
      // always the unit.
      return 1;
    }
  if (_id(str, QueryPluralIds(), QueryAds()))
  // Check if the unit identifies to <str>. If yes, the whole unit
  // is meant.
    {
      SetLastAmount(last+diff);
      return 1;
    }

  if (!str)
    return pLastTime = 0;

  // Up to now the unit didn't identify to <str>, so <str> contains
  // a part describing the amount.

  if (sizeof(s = explode(str, " ") - ({ "" })) < 2)
  // <str> is only one part. So there's no amount given.
    return pLastTime = 0;

  if (lower_case(s[0]) == "cada" && (::id(implode(s[1..], " "))))
  // 'every thing'
    {
      SetLastAmount(last+diff);
      return 1;
    }

  if (lower_case(s[0]) == "todo")
  {
    str=implode(s[1..], "");
    if (_id(str, QueryPluralIds(), QueryAds()))
       {
	  SetLastAmount(last+diff);
	  return 1;
       }
  }

  if (lower_case(s[0]) == "todos")
    {
      if (lower_case(s[1]) == "los")
        str = implode(s[2..], "");
      else
        str = implode(s[1..], "");
      if (_id(str, QueryPluralIds(), QueryAds()))
        {
          SetLastAmount(last+diff);
          return 1;
        }
      s[0..0] = ({});
    }

 if (lower_case(s[0]) == "todas")
  // 'all [the] things'
    {
      if (lower_case(s[1]) == "las")
        str = implode(s[2..], "");
      else
        str = implode(s[1..], "");
      if (_id(str, QueryPluralIds(), QueryAds()))
        {
          SetLastAmount(last+diff);
          return 1;
        }
      s[0..0] = ({});
    }

  if (   intp(a = atoi(s[0]))
      && a <= diff
      && _id( implode(s[1..], " "), a == 1 ? QueryIds() : QueryPluralIds()
            , QueryAds())
    )
  // '[all] <n> things'
  {
    SetLastAmount(a+last);
    return 1;
  }

  // Every test failed here.
  return pLastTime = 0;
}

//--- short description of a unit -------------------------------------------

public string PluralShort (mixed what, int amount)
{
  return itoa(amount)+" "+(QueryPluralShort() || (QueryShort()+"s"));
}

public string Short(mixed what)
{
  int lamount;
  string sh;

  sh = (::Short(what));
  if (!sh)  // Takes care of invisibility
    return sh;

  if (!QueryLastId()||query_verb()&&query_verb()!=QueryLastVerb())
  // Set the amount if not already done by id
    {
      SetLastAmount(QueryAmount());
      SetLastVerb(query_verb());
    }
  lamount = QueryLastAmount();
  //[n] Cambiado para que no ponga 'un venda'
  if ( TO->Query(P_GENDER)==GENERO_FEMENINO )
   return ( lamount == 1 ? "una "+sh : PluralShort(what, lamount) );

  return (lamount == 1 ? "un "+sh
                       : PluralShort(what, lamount)
         );
}

//--- long description of a unit -------------------------------------------

public string PluralLong (mixed what, int amount)
{
  return QueryPluralLong(what)||QueryLong();
}

public string Long(mixed what)
{
  int lamount;
  string lg;

  lg = (::Long(what));

  if (!QueryLastId())
  // Set the amount if not already done by id
      SetLastAmount(QueryAmount());
  lamount = QueryLastAmount();

  return (lamount == 1 ? lg : PluralLong(what, lamount) );
}


//--- moving parts or the whole unit ----------------------------------------

public int ReduceAmount(int amount)
{
  if (amount>QueryAmount()) return 0;
  SetAmount(QueryAmount()-amount);
  if (!QueryAmount())
    remove();
  return 1;
}

public object SplitOff (int amount)
{
  object ob;
  mapping prop;

  if (amount < 1 || amount > QueryAmount())
    return 0;

  if (QueryAmount() == amount)
    return TO;

  // clone another instance
  ob = clone_object(blueprint());
  prop = QueryProperties();
  prop = m_delete(prop,P_AMOUNT);
  prop = m_delete(prop,P_VALUE);
  prop = m_delete(prop,P_BRIGHT);
  prop = m_delete(prop,P_WEIGHT);
  prop = m_delete(prop,P_LIGHT);
  // Configure it to the rest amount of units
  ob->SetProperties(prop);
  ob->SetAmount(amount);
  ReduceAmount(amount);
  pLastTime--;
  return ob;
}

public int JoinWith (object ob)
{
  if (ob != TO && IsEqualTo(ob))
  {
    SetAmount(QueryAmount()+ob->QueryAmount());
    ob->remove();
    return 1;
  }
  return 0;
}

//--- moving parts or the whole unit ----------------------------------------

public varargs int move(mixed dest, int method, mixed extra)
{
  object otherob;
  int old_amount;
  int ret, i;
  object *inv, env;

  if (!QueryLastId())
  // If 'id' wasn't called up to now (e. g. when something is
  // cloning us.
    SetLastAmount(QueryAmount());

  if (method != M_NOCHECK && query_verb() && query_verb() != QueryLastVerb())
    {
      SetLastVerb(query_verb());
      SetLastAmount(QueryAmount());
    }

  if (   method == M_NOCHECK
      || !environment()
      || QueryLastAmount() == QueryAmount())
    ret = (::move (dest, method, extra));
  else
    {
      // backup old value
      old_amount = QueryAmount();

      // clone another instance
      // Configure it to the rest amount of units
      otherob = SplitOff(QueryAmount()-QueryLastAmount());

      // move me to the new destination
      env = environment();
      ret = (::move(dest, method, extra));

      // If failed, restore me and destruct other instance
      if ((ret != ME_OK) && (TO != otherob))
        {
          SetAmount(old_amount);
          if (otherob)
            destruct(otherob);  // Do it the hard way.
          return ret;
        }
      // our move succeeded, now move new ob (if there is one)
      // into old environ
      if (otherob)
        otherob->move(env,M_SILENT);
      // This moved with M_NOCHECK before! This way the weight
      // didn't get updated.
    }

  if (ret == ME_OK)
    filter(all_inventory(environment()),SF(JoinWith));

  return ret;
}
