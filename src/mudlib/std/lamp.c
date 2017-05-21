/** SIMAURIA '/std/lamp.c'
 *  ======================
 */

#include <config.h>
#include <lamp.h>
#include <properties.h>
#include <search.h>
#include <classes.h>
#include <messages.h>
#include <skills.h>

// -----------------------------------------------------------------------------

inherit THING;

// -----------------------------------------------------------------------------

#define BURN_UP_INTERVAL 300

#define FAIL(s)    return notify_fail(s, NOTIFY_NOT_OBJ)
#define FAILARG(s) return notify_fail(s, NOTIFY_NOT_VALID)

// -----------------------------------------------------------------------------

private object encendedor;

/*--------------------------------------------------------------------------*/

private int maxfuel, fuel, bright, burning, interval;
private int basevalue, fuelvalue, rechargeable;
private int baseweight, fuelweight;
private mixed *lamp_msg, fueltype;

/*----------------------------------------------------------------------------
** Initialize us - default is a torch
*/

create(){
  int i;

  "*"::create();
  AddClassId(C_LAMP);
  lamp_msg = allocate(PLM_MAX_MSGS);
  for (i=0; i<PLM_MAX_MSGS; lamp_msg[i++]="");
  bright = 1;
  interval = BURN_UP_INTERVAL;
}

init() {
  thing::init();
  add_action("flight", "encender");
  add_action("funlight", "apagar");
  add_action("funlight", "extinguir");
}

/*--------------------------------------------------------------------------
** Properties
*/

public int SetFuelMax (int v) { return maxfuel = v; }
public int QueryFuelMax () { return maxfuel; }

public int SetFuel (int v) {
  if (v > 0)
    AddClassAdj(CA_BURNABLE);
  else
    RemoveClassAdj(CA_BURNABLE);
  if (environment()) environment()->AddIntWeight(-((fuel - v) * fuelweight));
  return fuel = v;
}
public int QueryFuel () { return fuel; }

public int SetFuelWeight (int v) { return fuelweight = v; }
public int QueryFuelWeight () { return fuelweight; }

public int SetFuelValue (int v) { return fuelvalue = v; }
public int QueryFuelValue () { return fuelvalue; }

public mixed SetFuelType (mixed v) { return fueltype = v; }
public mixed QueryFuelType () { return fueltype; }

public int SetRechargeable(int i) { return rechargeable = i; }
public int QueryRechargeable() { return rechargeable; }


public int SetLampWeight (int v) { return baseweight = v; }
public int QueryLampWeight () { return baseweight; }

public int SetLampValue (int v) { return basevalue = v; }
public int QueryLampValue () { return basevalue; }

public int SetBurnStep (int v) { return interval = v; }
public int QueryBurnStep () { return interval; }

public int SetBrightness (int v) { return bright = v; }
public int QueryBrightness () { return bright; }

public mixed * SetLampMsg (mixed * v) { return lamp_msg = v; }
public mixed * QueryLampMsg () { return lamp_msg; }

public int QueryValue() { return basevalue + fuel * fuelvalue; }
public int SetValue(int v) { return QueryValue(); }
public int QueryWeight() { return baseweight + fuel * fuelweight; }
public int SetWeight(int w) { return QueryWeight(); }

public int QueryBurning () { return burning; }
public int SetBurning (int v) {
  int left, i, fuel;
  object env;

  while ((i = remove_call_out("BurnUp")) >= 0)
    left = i;
  if (!burning && v) {
    call_out("BurnUp", QueryBurnStep());
    SetBright(QueryBrightness());
    AddAdjective("ardiendo");
  }
  if (burning && !v) {
    if (left >= 0 && left * 2 < QueryBurnStep()) {
      SetFuel(fuel = QueryFuel()-1);
    }
    SetBright(0);
    RemoveAdjective("ardiendo");
  }
  return burning = v;
}

/*----------------------------------------------------------------------------
** Handle the lamp messages.
*/

public mixed LampMsg (int i) {
  mixed lmsg;

  lmsg = lamp_msg[i];
  if (closurep(lmsg))
    lmsg = (string)funcall(lmsg, i);
  if (stringp(lmsg))
    lmsg = process_string(lmsg);
  return (string)lmsg;
}

/*----------------------------------------------------------------------------
** Burn down, every interval seconds a bit.
** Return 1 if light is still on.
*/

public int BurnUp () {
  object env, pl;
  string pb;
  int fuel;
  mixed lmsg;

  if (!QueryBurning())
    return 0;
  SetFuel(fuel = QueryFuel()-1);

  if (fuel > 0 && QueryBurning()) {
    while(remove_call_out("BurnUp") >= 0);
    call_out( "BurnUp", interval);
    return 1;
  }
  if ((env = environment()) && interactive(env)) { /* We are carried */
    pl = env;
    if (lmsg = LampMsg(PLM_BURNED_UP))
        tell_object(pl, lmsg);
    env = environment(pl);
  }
  if (env && (lmsg = LampMsg(PLM_BURNED_UP_E)))
    tell_room(env, ({ MSG_SEE, lmsg }), ({ pl }));
  SetBurning(0);
  SetFuel(0);
  return 0;
}

/*----------------------------------------------------------------------------
** Simple interface
*/

public void SetLMsg (int index, string msg) { lamp_msg[index] = msg; }

public varargs void SetWeights (int lweight, int fweight) {
  SetLampWeight(lweight);
  SetFuelWeight(fweight);
}

public varargs void SetValues (int lvalue, int fvalue) {
  SetLampValue(lvalue);
  SetFuelValue(fvalue);
}

public varargs void SetFuelAmount (int current, int max) {
  if (!max) max = current;
  SetFuelMax(max);
  SetFuel(current);
}

/*----------------------------------------------------------------------------
** Command 'light'
*/

public varargs int flight (string str, int where)
{
    mixed lmsg, result;
    int tim;

    if (!str || -1 == member(TP->Search(str, where|SEARCH_IGNLIGHT)||({}), TO))
    {
        FAIL("¿"+capitalize(query_verb())+" qué?\n");
    }
    if (burning)
    {
        FAILARG(LampMsg(PLM_IS_BURNING) || "Ya la tienes encendida.\n");
    }
    if (!fuel)
    {
        FAILARG(LampMsg(PLM_NO_FUEL) || "No puedes encenderla.\n");
    }
    if (!result = search(TP, "lighter", SEARCH_INV))
    {
        FAILARG(LampMsg(PLM_NO_LIGHTER));
    }
    encendedor = result[0];
    if (TP->UseSkill(HAB_FIRE) >= - 10)
    {
        if (lmsg = LampMsg(PLM_LIGHT))
        {
            write(lmsg);
        }
        if (lmsg = LampMsg(PLM_LIGHT_E))
        {
            tell_room(environment(TP), ({ MSG_SEE, lmsg }), ({ TP }));
        }
        SetBurning(1);
        encendedor = 0;
        return 1;
    }
    if (   encendedor->Query("LastUse") == (tim = time()) || encendedor->Query("LastUse") == tim - 1
        || encendedor->Query("LastUse") == tim - 2)
    {
        encendedor->Set("Attempts", encendedor->Query("Attempts") + 1);
    }
    else
    {
        encendedor->Set("LastUse",time());
        encendedor->Set("Attempts", 0);
    }
    if (encendedor->Query("Attempts") >= 10)
    {
        load_object(CHANNELMASTER)->SendEmote("ainu", CAP(TNAME) +" está intentando subir la habilidad "
                    "de encender fuego con el dedito en el enter.\n");
        TP->remove();
        return 1;
    }
    tell_room(environment(TP), ({MSG_SEE, LampMsg(PLM_NO_FIRE_E)}), ({TP}));
    FAILARG(LampMsg(PLM_NO_FIRE));
}



/*----------------------------------------------------------------------------
** Command 'unlight'
*/

public varargs int funlight (string str, int where) {
  mixed lmsg;

  if (!str || -1 == member(TP->Search(str, where|SEARCH_IGNLIGHT)||({}), TO))
    FAIL("¿"+capitalize(query_verb())+" qué?\n");

  if (!burning)
    FAILARG(LampMsg(PLM_IS_DARK) || "No está encendida.\n");
  if (lmsg = LampMsg(PLM_UNLIGHT))
    write(lmsg);
  if (lmsg = LampMsg(PLM_UNLIGHT_E))
    tell_room(environment(TP), ({ MSG_SEE, lmsg }), ({ TP }));
  SetBurning(0);
  return 1;
}

/*----------------------------------------------------------------------------
** Compatibility.
*/

_light() { SetBright(1); return 0; }
_unlight() { SetBright(0); return 0; }

/*----------------------------------------------------------------------------
** For simple process_string()s, return the players name and gender_stuff
*/

string Lighter() { return encendedor ? encendedor->QueryShort() : ""; }
string Pl_Owner() {
  object pl;
  if ((pl = environment(TO)) && interactive(pl))
    return capitalize((string)pl->QueryName());
  return "a";
}
string Pl_Name() { return (string) TP->QueryName(); }
string Pl_Pro() { return (string) TP->QueryPronoun(); }
string Pl_Poss() { return (string) TP->QueryPossessive(); }
string Pl_Obj() { return (string) TP->QueryObjective(); }

/****************************************************************************/

//mixed QueryAutoObject() { return 1; }
