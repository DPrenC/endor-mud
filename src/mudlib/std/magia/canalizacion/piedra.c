/* SIMAURIA '/std/magia/canalizacion/piedra.c'
   ===========================================
   [t] theuzifan

   10-03-03 [t] Fusilación del corteza
*/

#include <ts.h>
#include <magia.h>
#include <properties.h>
#include <guild.h>
#include <spells.h>
#include <sounds.h>
inherit STD_SPELL;

#define ALREADY	"_piel_tr"
#define LVL	TP->QueryGuildLevel()

private object amuleto;

create()
{
  ::create();

  seteuid(getuid());
  SetSpellName(MAG_PIEDRA);
  SetSpellType(ST_PROTECT);
  SetSPCost(20);
  SetCastLevel(GC_GUARDABOSQUES,10);
  SetMemorizeLevel(GC_GUARDABOSQUES,15);
  SetTiredTime(2);
  SetSpellDescription("Convierte la piel en piedra.\n");
}

mixed Check(object caster, string args) {
  if (caster->Query(ALREADY)) {
    return notify_fail("Tu piel ya ha sido transformada.\n");
  }
  amuleto = present("amuleto de los guardabosques", caster);
  if (!amuleto) {
    return notify_fail("Has perdido tu amuleto de guardabosques. Sin él no "
    	"puedes realizar este tipo de magia.\n");
  }

  return 1;
}

int Cast(object caster, mixed mix) {
  object go;

  write("Empiezas a concentrarte y notas como la fuerza y la dureza "
  	"de los elementos más antiguos te invade... tu piel se transforma "
  	"en roca pura.\n");
  say("¡La piel de "+capitalize(caster->QueryName())+" parece cambiar y "
	  "convertirse en piedra!\n");

  amuleto->AddProperty(ALREADY, 1);
  amuleto->AddProperty(P_AC, 4+LVL/5);
  amuleto->ResetPropertiesByTime(LVL*8, ({P_AC, ALREADY}),
  	"Tu piel vuelve a su estado normal.\n", "La piel de "+
  	capitalize(caster->QueryName())+ " parece volver a su estado normal.\n");

  return 1;
}


int Fail(object caster, mixed mix) {
  write("Notas como tu piel se va volviendo lisa y dura. Pierdes "
  	"el contacto con la naturaleza y tu piel vuelve a ser lo que era.\n");

  say(capitalize(caster->QueryName())+" parece concentrarse durante unos "
  	  "instantes, pero no pasa nada.\n");

  return 1;
}
