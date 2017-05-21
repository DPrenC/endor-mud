/* SIMAURIA '/std/magia/canalizacion/sangre.c'
   =============================================
   [t] theuzifan

   28-10-99 [t] Creación.
   24-05-00 [t] Arreglado un fallo por el que se podía llamar las veces que se
   		quisiera al hechizo. Aumentado el ratio de curación,
   		dependiendo del acierto (anteriorRegHP*nivel/10, si nivel>30)
   		Por lo que el ratio de curación va desde 9 hasta 30...
   09-01-01 [t] Reescrito para adecuarse al amuleto.
   09-01-02 [t] (joer, que puntería... un año hace de esto...) Weno, remodifico el
   		ALREADY para que se resetee cuando debe, y dejarlo como en origen estaba,
   		o debería estar, con el AddProperties. Arreglo un fallo, detectado por
   		Maler, en el cual la llamada al ResetProperties tenía los dos primeros
   		parámetros cambiados.
   14-05-02 [t] Cambiado el write por el notify_fail en Check
*/

#include <ts.h>
#include <magia.h>
#include <properties.h>
#include <guild.h>
#include <sounds.h>
inherit STD_SPELL;

#define ALREADY  "_sangre"

private object amuleto;

create() {
  ::create();

  seteuid(getuid());
  SetSpellName("sangre de arbol");
  SetSpellType(ST_PROTECT);
  SetSPCost(25);
  SetCastLevel(GC_GUARDABOSQUES,1);
  SetMemorizeLevel(GC_GUARDABOSQUES,15);
  SetTiredTime(5);
  SetSpellDescription("Convierte la sangre en savia para regenerar la salud.\n");
}


mixed Check(object caster, string args) {
  if (caster->Query(ALREADY))   {
    return notify_fail("Tu sangre ya ha sido transformada.\n");
  }
  amuleto = present("amuleto de los guardabosques", caster);
  if (!amuleto) {
    return notify_fail(W("Has perdido tu amuleto de guardabosques. Sin él no "
    	"puedes realizar este tipo de magia.\n"));
  }

  return 1;
}

int Cast(object caster, mixed mix) {
  int level;

  write("Notas como tu sangre se vuelve más espesa. Sientes un torrente "
  	"de vida fluyendo por tus venas, revigorizándote y curándote.\n");

  say(capitalize(caster->QueryName())+" parece concentrarse durante unos "
  	  "instantes y parece revigorizado, pero aparte de esto no aprecias "
  	  "ningún resultado visible.\n");

  level = 3+caster->QueryGuildLevel()/10;
  if (level>10) level = 10;
  amuleto->AddProperty(ALREADY, 1);
  amuleto->AddProperty(P_REG_HP, level);
  
  level = 10+5*caster->QueryGuildLevel();
  if (level>300) level = 300; // 5 minutos maximo
  amuleto->ResetPropertiesByTime(level, ({P_REG_HP, ALREADY}),
  	"Notas como tu sangre cambia y vuelve a su estado normal.\n");

  return 1;
}


int Fail(object caster, mixed mix) {
  write("Notas como tu sangre comienza a espesarse, pero en seguida pierde "
  	"consistencia y vuelve a su estado normal.\n");

  say(capitalize(caster->QueryName())+" parece concentrarse durante unos "
  	  "instantes, pero no pasa nada.\n");

  return 1;
}


