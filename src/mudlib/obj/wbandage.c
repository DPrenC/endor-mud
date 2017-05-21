// [t] 11-03-03 Arreglado!!!!
// Venda llevada en un momento determinado
// hecha por Magictcs@NightFall 27/11/96 para el gremio de Paladines

#include <config.h>
#include <search.h>
#include <combat.h>
#include <properties.h>
#include <equipment.h>
#include <moving.h>
#include <materials.h>

inherit ARMOUR;
nosave int count, percent;

int QueryCount() {
	return count;
}
int SetCount(int to) {
	return count = to;
}
int SetPercent(int to) {
	return percent = to;
}
int QueryPercent() {
	return percent;
}

public varargs void NotifyEquip(object liv, object armour, int flags) {
  if (armour != TO) return;
    
  call_out("start_heal",1, percent);
  
  ::NotifyEquip(liv, armour, flags);
}
	
// No protege nada
int Defend (object enemy, int damage, int type){ return 0; }

// calls the healing and removing functions
private void CheckHeal()
{
  object env,ob;
  while(remove_call_out(SF(CheckHeal))!=-1);
  if (!(env = environment())||!living(env)) return;
  if (env->QueryHealth() == 100 || count<1)
  {
      tell_object(env,"La venda se suelta.\n");
      Unequip();
      SetNoDrop(0);
      remove();         // remove the bandage
      return;
    }
  env->HealHP(1+percent/10);
  tell_object(env,"La venda escuece un poco.\n");
  count--;
  call_out(SF(CheckHeal),5+random(5));
}

// start the healing process
public void start_heal(int percent) {
  call_out(SF(CheckHeal),5+random(5));
}

public varargs mixed ChkEquip(object liv, object weapon, int flags) {
  if (weapon != TO) return EQ_OK;
	if (query_verb() && query_verb() != "vendar") {
		return "Para ponértela debes usar el comando 'vendar'.\n";
	}
	
	return ::ChkEquip(liv, weapon, flags);
}

int _check() {
	return find_call_out("CheckHeal");
}

public varargs mixed ChkUnequip(object liv, object weapon, int flags) {
	if (!find_call_out(SF(CheckHeal))) {
		call_out("remove", 1);
		return ::ChkUnequip(liv, weapon, flags);
	}
	return "Todavía no te puedes quitar la venda.\n";
}

int remove()
{
	   tell_object(environment(),"La venda queda hecha jirones...\n");
	   return ::remove();
}

public int cmd_bandage(string str)
{
  return notify_fail("Ya estás usando la venda.\n"),0;
}

public void create()
{
  ::create();
  SetStandard(AT_CASCO, 0, P_SIZE_GENERIC, M_TELA);
  SetShort("una venda");
  SetLong("Sirve para vendar a la gente.\n");
  SetWeight(50);
  Set(P_GENDER, GENERO_FEMENINO);
  AddId(({"venda","wbandage"}));
  SetAds(({"en uso"}));
  RemoveClassId("armadura");
  RemoveId("casco");
  SetNoDrop("No puedes tirar la venda.\n");
  Set(P_CANT_STEAL,1);
}

public void init()
{
  (::init());
  add_action("cmd_bandage","vendar");
}
