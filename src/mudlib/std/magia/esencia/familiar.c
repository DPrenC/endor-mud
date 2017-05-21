
/* SIMAURIA '/std/magia/esencia/familiar.c'
   ========================================
   [w] Woo@simauria

   14-02-00 [w] Conjuro de los conjuradores.
   28-03-00 [w] Modificado ya que confundia las esferas luminosas
                con los familiares.
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <sounds.h>
inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())

create() {
  ::create();
  SetSpellName("Familiar");
  SetSpellUse("a <objetivo>");
  SetSpellType(ST_INFLUENCE);
  SetSPCost(15);
  SetCastLevel(GC_CONJURADORES,1);
  SetMemorizeLevel(GC_CONJURADORES,10);
  SetTiredTime(2);
  SetSpellXP(10);
  SetSpellDescription(
"Conviertes a algún pequeño animal que sea facil de controlar en tu familiar.\n\
Éste te seguirá donde quiera que vayas y hará que tus puntos de magia aumenten\n\
con mayor rapidez. Puedes darle un nuevo nombre con 'nombre <nuevo>'\n");
 }

mixed Check(object caster, string args) {
  string quien;
  object enemigo;

  if (!sizeof(args) || sscanf(args,"a %s", quien)!=1)
    return notify_fail("¿A quién quieres hacer tu familiar?\n");

  if (!enemigo=present(quien, environment(caster)))
    return notify_fail("No puedes ver a "+quien+" aquí.\n");

  if (!living(enemigo))
    return notify_fail("No creo que a eso le afecte mucho.\n");

  if(enemigo==caster)
    return notify_fail("¿Quieres ser tu propio familiar?\n");

  if (!enemigo->QueryFamiliar())
    return notify_fail("Deberias buscar a algún animal fácilmente influenciable.\n");

  if (enemigo->QueryOwner())
    return notify_fail("Ese animal ya tiene dueño. ¿Quieres provocar un combate?\n");

  if (caster->QueryFollowers()) foreach(object o: caster->QueryFollowers()) {
    if (!o) continue; // [Nyh] No se por que, pero hoy uno tenia a 0 de follower
    if (o->QueryFamiliar())
	  return notify_fail("No pretenderás ser un Mesias y que te sigan todos los animales, ¿no?\n");
  }

  if (!CanCastSpell(enemigo)) return 0;

  write("Extiendes la mano y la colocas justo en frente de "+enemigo->QueryName()+".\n");
  say(capitalize(caster->QueryName())+" extiende la mano y la coloca justo en frente de "
       +enemigo->QueryName()+".\n",({caster, enemigo}));
  tell_object(enemigo, caster->QueryName()+" extiende su mano y la coloca en tu frente.\n");

  return enemigo;
}

int Cast(object caster, mixed enemigo) {

  write("Sientes como te tiene poco a poco más confianza. ¡Bien!, "
        "lo has conseguido, ahora te seguirá a donde quiera que vayas.\n");

  play_sound(ENV(caster), SND_MAGIA("conjuro"));
  enemigo->SetFamiliar(caster);

  return 1;
}


int Fail(object caster, mixed enemigo) {
  play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));
  write("Sientes como te tiene poco a poco más confianza, "
        "pero no consigues que se convierta en tu familiar. "
        "Quizás si lo intentases de nuevo.\n");

  return 1;
}


