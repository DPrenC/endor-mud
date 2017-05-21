/* SIMAURIA '/std/magia/canalizacion/convocar.c'
   =============================================
   [t] theuzifan

   25-10-99 [t] Creación.
   24-05-00 [t] Los animales que crees te seguirás hasta que entres en combate,
   		dejando de seguirte. Entonces pasan a perseguir a los animales
   		a los que estás matando, y les seguirán hasta que uno de los
   		dos muera.
   14-05-02 [t] Ya no se puede convocar a miles y miles de animales.
   15-05-02 [t] Arreglado el fallo del remove() -> se le pasaba perc = 0.
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <sounds.h>
inherit STD_SPELL;

#define ALREADY  "_convocar"
#define NUMCALL "_numcall"

private object amuleto;

create() {
  ::create();

  seteuid(getuid());
  SetSpellName("Convocar animales");
  SetSpellType(ST_SUMMON);
  SetSPCost(20);
  SetCastLevel(GC_GUARDABOSQUES,1);
  SetMemorizeLevel(GC_GUARDABOSQUES,10);
  SetTiredTime(5);
  SetSpellDescription("Convoca a un pequeño grupo de animales.\n");
}

int create_followers(object caster, string what, int num, int perc) {
  object ob;
  int i;

  for (i=0; i<num; i++)
  {
    ob=clone_object("/guilds/guardabosques/pnj/special/"+what);
    ob->move(environment(TP));
    ob->FollowsTo(TP, perc);
  }
  write("Consigues convocar a "+itoa(num)+" "+ob->QueryRace()+(num>1?"s":"")+".\n");

  return 1;
}


int Cast(object caster, mixed mix) {
  object ob, env;
  int acierto;

  amuleto->AddProperty(ALREADY, 1);
  caster->Set(NUMCALL, 0);
  write("Te concentras y notas que la esencia de los bosques entra en tí. "
  	"Mentalmente buscas a algún animal que esté en las cercanías y que "
  	"quiera ayudarte.\n");

  say(capitalize(caster->QueryName())+" parece concentrarse durante unos "
  	"instantes. Escuchas los sonidos de algún animal que se acerca, y "
  	+capitalize(caster->QueryName())+" sale de su ensimismamiento.\n");

	acierto = caster->QueryGuildLevel();
	acierto = ((random(acierto)+random(acierto))>>2) + caster->QueryInt();
	if (acierto>100) acierto = 100;
  switch (acierto) {
    case 1..5: return create_followers(caster, "ardilla", 1, acierto);
    case 6..12: return create_followers(caster, "conejo", 2, acierto);
    case 13..20: return create_followers(caster, "topo", 2, acierto);
    case 21..30: return create_followers(caster, "ciervo", 2, acierto);
    case 31..36: return create_followers(caster, "jabali", 1+random(3), acierto);
    case 37..45: return create_followers(caster, "zorro", 1+random(3), acierto);
    case 46..75: return create_followers(caster, "lobo", 3+random(3), acierto);
    default: return create_followers(caster, "oso", 4+random(4), acierto);
  }
  amuleto->ResetPropertiesByTime(15*acierto, ({ALREADY}),
  	"Los animales convocados vuelven a su lugar de origen.\n",
  	"Los animales que protegían a " + capitalize(caster->QueryName()) +
  	" vuelven a su lugar de origen.\n");

  return 1;
}


int Fail(object caster, mixed mix) {
  write("Te concentras y notas que la esencia de los bosques entra en tí. "
  	"Mentalmente buscas a algún animal que esté en las cercanías y que "
  	"quiera ayudarte. Algo te desconcentra y pierdes el contacto con la "
  	"naturaleza.\n");

  say(capitalize(caster->QueryName())+" intenta concentrarse durante unos "
  	"instantes, pero parece que no lo consigue.\n");

  return 1;
}

mixed Check(object caster, string args) {
  if (caster->Query(ALREADY) && caster->Query(NUMCALL) > 0) {
    return notify_fail("Ya has convocado a varios animales. Debes esperar un rato más.\n");
  }
  amuleto = present("amuleto de los guardabosques", caster);
  if (!amuleto) {
    return notify_fail("Has perdido tu amuleto de guardabosques. Sin él no "
    	"puedes realizar este tipo de magia.\n");
  }

  return 1;
}

