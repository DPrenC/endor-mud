/* SIMAURIA '/std/magia/canalizacion/calmar.c'
   =============================================
   [t] theuzifan

   25-10-99 [t] Creación.
   29-02-00 [t] Modificación de las razas que se pueden calmar.
   24-05-00 [t] Cambiado totalmente. Ahora se pueden calmar TODAS las
   		razas menos las creadas por artes no naturales, como los
   		zombies, ghouls, etc. La dificultad la marca la
   		diferencia de nivel entre el conjurador y el animal a
   		ser calmado.
*/

#include <magia.h>
#include <ts.h>
#include <properties.h>
#include <guild.h>
#include <sounds.h>
inherit STD_SPELL;

/*
#define allowed_races ({"ardilla", "cocodrilo", "halcon", "oso", "pollo", \
		"caballo", "conejo", "mono", "panda", "tigre", "ciervo", \
		"jabali", "lobo", "topo", "jabalí", "zorro"})
*/

#define disallowed_races ({"esqueleto","zombie","ghoul","shad","elemental"})

create() {
  ::create();

  seteuid(getuid());
  SetSpellName("Calmar animal");
  SetSpellType(ST_INFLUENCE);
  SetSpellUse("<objetivo>");
  SetSPCost(15);
  SetCastLevel(GC_GUARDABOSQUES,1);
  SetMemorizeLevel(GC_GUARDABOSQUES,8);
  SetSaveType(SAVE_TYPE_WILL);  
  SetSpellDescription("Calma a un animal.\n");
}

mixed Check(object caster, string args) {
  object contra;
  
  if (!sizeof(args)) return notify_fail("¿Calmar a quién?\n");

  if (!contra=present(args, environment(caster)))
    return notify_fail("No puedes ver a "+args+" aquí.\n");

  if (!living(contra))
    return notify_fail("¡No puedes calmar a algo inerte!\n");

  if (!sizeof(contra->QueryEnemies()))
    return notify_fail(capitalize(contra->QueryShort())+" no está luchando "
    	"contra nadie.\n");
    	
  if (member(disallowed_races, contra->QueryRace())!=-1)
    return notify_fail("No sabes como calmar a "+args+".\n");

  write("Dejas de atacar a "+contra->QueryShort()+" y te concentras en su mente para calmarle.\n");
  say(capitalize(caster->QueryName())+" clava sus ojos en "+contra->QueryShort()+" y se concentra.\n"
     , ({caster, contra}));
  tell_object(contra, capitalize(caster->QueryName())+" clava sus ojos ti y se concentra.\n");

  caster->StopHunting(contra);
	
  return contra;
}

private void _hit(object caster, object contra) {
  play_sound(ENV(caster),SND_MAGIA("calmar.mp3"));

  write("Consigues calmar a "+contra->QueryShort()+".\n");
  say(capitalize(contra->QueryShort())+" parece calmarse.\n", ({caster, contra}));
  tell_object(contra, "Te sientes muy tranquilo.\n");
  
  contra->StopAttack();
}

private void _miss(object caster, object contra) {
  play_sound(ENV(caster),SND_MAGIA("fallarcalmar.mp3"));

  write("No consigues calmar a "+contra->QueryShort()+".\n");
//  say(capitalize(contra->QueryShort())+" no parece calmarse.\n", ({caster, contra}));
  tell_object(contra, "Notas como "+caster->QueryShort()+
    " intenta entrar en tu mente para calmarte, pero no lo consigue.\n");
}

//map es un mapping con el objetivo y su tirada de salvacion, SOLO deberia
// haber uno, pero como me mola el foreach lo uso.
int Cast(object caster, mixed map) {  
  foreach(object contra, int acierto: map) {
	if (acierto>0) _hit(caster, contra);
	else _miss(caster, contra);
  }

  return 1;
}

// En este conjuro como solo hay un objetivo contra deberia ser object
int Fail(object caster, mixed contra) {

  write("Te concentras e intentas imponer tu mente a la de "+
    contra->QueryShort()+", ¡pero sólo consigues que se enfurezca en "
  	"tu contra!\n");

  say(capitalize(caster->QueryName())+" parece concentrarse durante unos "
    "instantes, ¡y "+contra->QueryShort()+" se enfurece!\n");
  contra->DoAttack(caster);
  
  return 1;
}

