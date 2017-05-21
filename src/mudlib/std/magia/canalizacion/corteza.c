/* SIMAURIA '/std/magia/canalizacion/corteza.c'
   =============================================
   [t] theuzifan

   28-10-99 [t] Creación.
   24-05-00 [t] Añade AC al caster. Ze me orvidó :)
   09-01-01 [t] Reescrito para usar la funcionalidad del amuleto.
   09-01-02 [t] (joer, que puntería... un año hace de esto...) Weno, remodifico el
   		ALREADY para que se resetee cuando debe, y dejarlo como en origen estaba,
   		o debería estar, con el AddProperties.
   14-05-02 [t] Cambiado el write por el notify_fail en Check
*/

#include <ts.h>
#include <magia.h>
#include <properties.h>
#include <guild.h>
#include <spells.h>
#include <sounds.h>
inherit STD_SPELL;

#define ALREADY        "_piel_tr"
#define LVL	TP->QueryGuildLevel()

private object amuleto;

create() {
  ::create();

  seteuid(getuid());
  SetSpellName(MAG_CORTEZA);
  SetSpellType(ST_PROTECT);
  SetSPCost(10);
  SetCastLevel(GC_GUARDABOSQUES,1);
  SetMemorizeLevel(GC_GUARDABOSQUES,5);
  SetTiredTime(4);
  SetSpellDescription("Convierte la piel en algo tan duro como "
	"la corteza.\n");
}

mixed Check(object caster, string args) {
  if (caster->Query(ALREADY))   {
    return notify_fail("Tu piel ya ha cambiado.\n");
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

  write("Notas como tu piel se va volviendo más rugosa y dura. Poco a poco "
  	"va cogiendo la consistencia de la corteza de los árboles. Has "
	"convertido tu piel en corteza.\n");
  say("¡La piel de "+capitalize(caster->QueryName())+" parece cambiar y "
	"convertirse en corteza!\n");

  amuleto->AddProperty(ALREADY, 1);
  amuleto->AddProperty(P_AC, 3+LVL/8);
  amuleto->ResetPropertiesByTime(LVL*10, ({P_AC, ALREADY}),
  	"Tu piel vuelve a su estado normal.\n", "La piel de "+
  	capitalize(caster->QueryName())+ " parece volver a su estado normal.\n");

  return 1;
}

int Fail(object caster, mixed mix) {
  write("Notas como tu piel se va volviendo más rugosa y dura. Pierdes "
  	"el contacto con la naturaleza y tu piel vuelve a ser lo que era.\n");

  say(capitalize(caster->QueryName())+" parece concentrarse durante unos "
  	  "instantes, pero no pasa nada.\n");

  return 1;
}


