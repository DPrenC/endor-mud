/* SIMAURIA '/std/magia/canalizacion/transmutar.c'
   ===============================================
   [t] theuzifan

   29-02-00 [t] Creación.
   27-07-00 [t] El animal transmutado desempuña las armas... si no pegaría
   		tb con ellas.
   09-01-01 [t] Reescrito para que se reinicie el estado al salir.
   09-01-02 [t] (joer, que puntería... un año hace de esto...) Weno, remodifico el
   		ALREADY para que se resetee cuando debe, y dejarlo como en origen estaba,
   		o debería estar, con el AddProperties.
   14-05-02 [t] Cambiado el write por el notify_fail en Check
   05-06-02 [t] Arreglado el IVISION.
*/

#include <ts.h>
#include <magia.h>
#include <properties.h>
#include <guild.h>
#include <attributes.h>
#include <colours.h>
#include <sounds.h>
inherit STD_SPELL;

#define LVL	TP->QueryGuildLevel()
#define ALREADY "_transmutar"

private object amuleto;

create() {
  ::create();

  seteuid(getuid());
  SetSpellName("Transmutación");
  SetSpellType(ST_CHANGE);
  SetSpellUse("");
  SetSPCost(50);
  SetTiredTime(5);
  SetCastLevel(GC_GUARDABOSQUES,1);
  SetMemorizeLevel(GC_GUARDABOSQUES,15);
  SetSpellDescription("Transmutación en animal.\n");
}


mixed Check(object caster, string args) {
  object environ;

  if (caster->Query(ALREADY))
    return notify_fail("Tu cuerpo ya ha transmutado.\n");

  amuleto = present("amuleto de los guardabosques", caster);
  if (!amuleto) {
    return notify_fail(W("Has perdido tu amuleto de guardabosques. Sin él no "
    	"puedes realizar este tipo de magia.\n"));
  }
  environ = environment(caster);
  if (!environ) return 1;

  return 1;
}

static void set_common_properties(object ob, int acierto) {
  int ivision, uvision;

  amuleto->AddProperty(P_SP, 0);
  amuleto->AddProperty(P_REG_SP, 0);
  amuleto->AddProperty(P_TMPINT, 1);
  ivision = ob->Query(P_IVISION);
  if (ivision < 0) {
  	ivision *= 2;
  }
  else {
  	ivision /= 2;
  }
  uvision = ob->Query(P_UVISION);
  amuleto->AddProperty(P_UVISION, uvision);
  amuleto->AddProperty(P_IVISION, ivision);
  amuleto->AddProperty(ALREADY, 1);
}

static void set_wolf_properties(object ob, int acierto)
{
  int vida = TP->QueryHP(), max_vida = TP->QueryMaxHP();
  amuleto->AddProperty(P_TMPDEX, 35);
  amuleto->AddProperty(P_TMPCON, 35);
  amuleto->AddProperty(P_TMPSTR, 35);
  amuleto->AddProperty(P_SHORT, "un enorme lobo");
  amuleto->AddProperty(P_LONG, "Un enorme lobo gris.\n");
  amuleto->AddProperty(P_HANDS, ({({"las garras", TD_CORTE, 10}), ({"un mordisco", TD_CORTE, 12})}));
  if (max_vida < TP->QueryMaxHP())
  // el máximo de vida le ha subido
  {
    TP->SetHP((TP->QueryMaxHP() * vida) / max_vida);
  }
  set_common_properties(ob, acierto);
}

static void set_bear_properties(object ob, int acierto)
{
  int vida = TP->QueryHP(), max_vida = TP->QueryMaxHP();
  amuleto->AddProperty(P_TMPDEX, 45);
  amuleto->AddProperty(P_TMPCON, 45);
  amuleto->AddProperty(P_TMPSTR, 45);
  amuleto->AddProperty(P_SHORT, "un enorme oso");
  amuleto->AddProperty(P_LONG, "Un enorme oso pardo.\n");
  amuleto->AddProperty(P_HANDS, ({({"las garras", TD_CORTE, 15}), ({"un mordisco", TD_CORTE, 17})}));
  if (max_vida < TP->QueryMaxHP())
  // el máximo de vida le ha subido
  {
    TP->SetHP((TP->QueryMaxHP() * vida) / max_vida);
  }
  set_common_properties(ob, acierto);
}

int Cast(object caster, mixed mix) {
  object *inv;
  int i, acierto;

  acierto = caster->QueryGuildLevel();
  acierto = ((random(acierto)+random(acierto))>>2) + caster->QueryInt();
  if (acierto>100) acierto = 100;

  if (acierto>50) set_bear_properties(caster, acierto);
  else set_wolf_properties(caster, acierto);

  foreach(object o: all_inventory(caster)) {
    if (o->Query(P_EQUIPPED)) o->Unequip();
  }

  write("Tu cuerpo empieza a cambiar. Una gruesa capa de pelo empieza "
    	"a crecer justo por debajo de tu piel, creándote un inmenso dolor. "
    	"Tus mandíbulas empiezan a desarrollarse así como tu cuerpo, "
    	"y notas cómo una fuerza brutal te invade. Te conviertes en "+
    	caster->QueryShort()+".\n");

  say(capitalize(caster->QueryName())+" empieza a cambiar y a transformarse. "
  	"Su cuerpo empieza a llenarse de pelo y a crecer, y sus mandíbulas "
  	"empiezan a cambiar y a desarrollarse. Se convierte en "+
  	caster->QueryShort()+".\n");

  amuleto->ResetPropertiesByTime(5+2*acierto,
  	({P_SHORT, P_LONG, P_HANDS, P_UVISION, P_IVISION, ALREADY,
  		P_TMPSTR, P_TMPDEX, P_TMPINT, P_TMPCON, P_DEFENCES,
  		P_SP,P_REG_SP}),
	TC_BOLD+"Vuelves a tu estado habitual"+TC_NORMAL+".\n",
  	"El cuerpo de "+caster->QueryRealName()+ " se transforma y "
  	"vuelve a su estado natural.\n");

  caster->SetTiredMagic((5+2*acierto) / 2);

  return 1;
}


int Fail(object caster, mixed mix) {
  write("Te concentras e intentas transmutar tu cuerpo, pero no lo "
  	"consigues.\n");

  say(capitalize(caster->QueryName())+" parece concentrarse durante unos "
  	  "instantes, pero no pasa nada.\n");

  return 1;
}