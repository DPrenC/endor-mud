/***************************************************************************************
 ARCHIVO:	maestro_base.c
 AUTOR:		[z] Zomax
 FECHA:		30-12-2001
 COMENTARIOS:	Un maestro del templo.
 MODIFICACION:	20-04-2003 Cambio radical para adaptarlo al nuevo combat. Ahora como
			lanza hechizos es un spellmonster y los lanza de verdad.
		05-05-2003 Quitadas defensas.
		11-05-2003 Bajo niveles de Standard
		12-06-2003 Bajo HP al Standard
 		12-06-2003 [Nyh] Retoco muchas cosas
 ***************************************************************************************/

#include "path.h"
#include <spellmonster.h>
#include <colours.h>
#include <combat.h>
#include <gremios.h>
#include <properties.h>
#include <moving.h>

inherit SPELLMONSTER;
inherit GUARD;

#define SPELL_MIN_DAM	5
#define SPELL_MAX_DAM	25
#define SPELL_SP	15

public mapping fcurarse(mapping spell) {
  int dif;
  dif = QueryMaxHP() - QueryHP();
  if (dif>0) {
    AddHP(random(dif));
    if (environment(TO)) tell_room(environment(TO),TC_WHITE+TC_BOLD+"  El maestro se concentra, un aura le rodea y le cura algunas heridas.\n"+TC_NORMAL);
  }
  return spell;
}

public mapping frecuperar(mapping spell) {
  int dif;
  dif = QueryMaxSP() - QuerySP();
  if (dif>0) {
    AddHP(random(dif));
    if (environment(TO)) tell_room(environment(TO),TC_WHITE+TC_BOLD+"  El maestro se concentra y recupera fuerza de espítitu.\n"+TC_NORMAL);
  }
  return spell;
}

public mapping festado(mapping spell) {
  if (QuerySP()>50 && QueryHP()<150 && random(2)) {
    fcurarse(spell);
    AddSP(-10);
    return 0;
  }
  else if (QuerySP()< 50) {
    if (random(2)) frecuperar(spell);
    if (QuerySP()>10 && !random(3)) {
      fcurarse(spell);
      AddSP(-10);
      return 0;
    }
  }
  return spell;
}

protected void GiveMaestroSpells() {
  SetCastChance(100);
  AddSpell("FIREBALL",([
        S_CHANCE:	100,
        S_FUN:		SF(festado),
        S_SIMULT:	0,
        S_VICTIMS:	1,
        S_DAMTYPE:	MT_FIRE,
        S_COMBAT_DELAY:	0,
        S_MINDAM:	SPELL_MIN_DAM,
        S_MAXDAM:	SPELL_MAX_DAM,
        S_SP:		SPELL_SP,
        S_VICMSG:	([MSG_NORMAL:	TC_BOLD+TC_RED+QueryName()+" agita las manos y te lanza una bola de fuego que te abrasa la piel hasta lo más profundo."TC_NORMAL]),
        S_ENVMSG:	([MSG_NORMAL:	TC_BOLD+TC_RED+QueryName()+" agita las manos y lanza una bola de fuego que abrasa la piel de @@VicName|1@@ hasta lo más profundo."TC_NORMAL]),
        ])
  );
  AddSpell("ROCKS",([
        S_CHANCE:	100,
        S_FUN:		SF(festado),
        S_SIMULT:	0,
        S_VICTIMS:	1,
        S_DAMTYPE:	MT_BLUDGEON,
        S_COMBAT_DELAY:	0,
        S_MINDAM:	SPELL_MIN_DAM,
        S_MAXDAM:	SPELL_MAX_DAM,
        S_SP:		SPELL_SP,
        S_VICMSG:	([MSG_NORMAL:	TC_YELLOW+QueryName()+" extiende los brazos y te lanza unas pesadas rocas que te aplastan los huesos."TC_NORMAL]),
        S_ENVMSG:	([MSG_NORMAL:	TC_YELLOW+QueryName()+" extiende los brazos y lanza unas pesadas rocas que aplastan los huesos de @@VicName|1@@."TC_NORMAL]),
        ])
  );
  AddSpell("ICE",([
        S_CHANCE:	100,
        S_FUN:		SF(festado),
        S_SIMULT:	0,
        S_VICTIMS:	1,
        S_DAMTYPE:	MT_PIERCE,
        S_COMBAT_DELAY:	0,
        S_MINDAM:	SPELL_MIN_DAM,
        S_MAXDAM:	SPELL_MAX_DAM,
        S_SP:		SPELL_SP,
        S_VICMSG:	([MSG_NORMAL:	TC_BOLD+TC_WHITE+QueryName()+" alza las manos y te lanza unos cristales de hielo que te perforan las entrañas."TC_NORMAL]),
        S_ENVMSG:	([MSG_NORMAL:	TC_BOLD+TC_WHITE+QueryName()+" alza las manos y lanza unos cristales de hielo que perforan las entrañas de @@VicName|1@@."TC_NORMAL]),
        ])
  );
  AddSpell("THUNDER",([
        S_CHANCE:	100,
        S_FUN:		SF(festado),
        S_SIMULT:	0,
        S_VICTIMS:	1,
        S_DAMTYPE:	MT_ELECTRO,
        S_COMBAT_DELAY:	0,
        S_MINDAM:	SPELL_MIN_DAM,
        S_MAXDAM:	SPELL_MAX_DAM,
        S_SP:		SPELL_SP,
        S_VICMSG:	([MSG_NORMAL:	TC_BOLD+TC_YELLOW+QueryName()+" te apunta con el dedo y te lanza un rayo que te fulmina."TC_NORMAL]),
        S_ENVMSG:	([MSG_NORMAL:	TC_BOLD+TC_YELLOW+QueryName()+" apunta con el dedo a @@VicName|1@@ y le lanza un rayo que le fulmina."TC_NORMAL]),
        ])
  );
}

create(){
  "*"::create();

  SetStandard("un maestro","humano",([GC_MAGO: 23+random(5)]),GENERO_MASCULINO);
  SetAlign(0);
  SetWhimpy(0);
  SetGoChance(25);
  SetAggressive(1);
  SetCitizenship("seri");
  SetGuardDefendMsg("Un maestro grita uniéndose al combate:\n ¡No permitiré que "
    "se mancille el nombre de Saenetia derramando sangre en su morada!\n");
  SetAds(({"un","el"}));
  SetIds(({"maestro","humano"}));
  SetShort("un maestro");
  SetLong(W("Miras a uno de los maestros del templo. Es un humano de mirada "
    "inquietante. No parece muy fuerte, más por edad que por condición "
    "física, porque sin duda en su época lo fue, pero por lo seguro que "
    "está de si mismo dirías que guarda algún tipo de secreto muy "
    "desagradable si le atacas.\n"));

  GiveMaestroSpells();

  if (!random(3)) AddItem(RHOEVAR("seri/llave_cylin"),REFRESH_REMOVE);
  AddItem(RHOEARM("seri/maestro/sandalias"),REFRESH_REMOVE,	SF(wearme));
  AddItem(RHOEARM("seri/maestro/tunica"),REFRESH_REMOVE,	SF(wearme));
}

public varargs int move(mixed dest, int method, mixed stuff) {
  if (environment(TO) && method==M_GO && dest->QueryLocate()!=environment(TO)->QueryLocate())
    return ME_NO_ENTER;
  return ::move(dest,method,stuff);
}
