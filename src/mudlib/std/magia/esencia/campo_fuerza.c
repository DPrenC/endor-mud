/* SIMAURIA '/std/magia/esencia/campo_fuerza.c'
   ===========================================
   [m] Maler

   25-11-99 [w] Conjuro de los conjuradores.
   27-01-99 [w] Cambiado el SetCombatDelay que tenia los argumentos al
                contrario y petaba.
   15-02-00 [w] Ahora solo te quedas rigido durante 1 segundo.
   14-11-00 [m] mango a saco.
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <sounds.h>
inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())

create() {
  ::create();
  SetSpellName("Campo de Fuerza");
  SetSpellUse("[contra <objetivo>]");
  SetSpellType(ST_PROTECT);
  SetSPCost(20);
  SetCastLevel(GC_HECHICEROS,7);
  SetMemorizeLevel(GC_HECHICEROS,13);
  SetTiredTime(4);
  SetSpellXP(25);
  SetSpellDescription("\
Creas por un tiempo limitado una campo de fuerza. El campo de fuerza\n\
absorve una parte del daño que recibes.\n");
}

mixed Check(object caster, string args) {
  string quien;
  object jugador;
  
  if (!sizeof(args)) {
    jugador = caster;
    if (present("conjuro_campo_fuerza",jugador))
      return notify_fail("No resistirías el efecto de este conjuro por duplicado.\n");
    return jugador;
  }
  
  if (jugador==caster) {
    if (present("conjuro_campo_fuerza",jugador))
      return notify_fail("No resistirías el efecto de este conjuro por duplicado.\n");
    return jugador;
  }
  
  if (!living(jugador))
    return notify_fail("Este conjuro solo afecta a seres vivos.\n");
  
  if (present("conjuro_campo_fuerza",jugador))
    return notify_fail(capitalize(jugador->QueryName())+" no resistiría el efecto de este conjuro por duplicado.\n");

  write("Te concentras, extrayendo energía de todas las cosas que te rodean.\n"
        "Dices: Kevlâr.\n");
   say(capitalize(caster->QueryName())+" cierra los ojos y millones de puntos de luz se concentran a su alrededor.\n"+
       capitalize(caster->QueryName())+" dice: Kevlâr.\n");      
  
  return jugador;
}

int Cast(object caster, mixed jugador) {
 int tiempo;
 object magic_obj;

 seteuid(getuid(TO));
 tiempo = 30*caster->QueryGuildLevel();
 magic_obj=clone_object("/guilds/hechiceros/obj/campo_fuerza");
 magic_obj->Endurecer(jugador, tiempo);

 if (caster==jugador)
 {
   play_sound(ENV(caster),SND_MAGIA("campo.mp3"));

   write("Un brillante campo de fuerza aparece de la nada, rodeándote.\n");
   say("Al instante un brillante campo de fuerza aparece de la nada, rodeando a "
       + capitalize(caster->QueryName()) + ".\n", ({caster}));

  }
  return 1;
}

int Fail(object caster, mixed jugador) {
  play_sound(ENV(caster),SND_MAGIA("fallarcampo.mp3"));
  write("Te das cuenta de que has debido fallar en los gestos o en la frase, "
        "porque la energía que te rodea te daña.\n");
  say(capitalize(caster->QueryName())+" abre los ojos asustado, mientras las "
      "luces penetran en su cuerpo y se estremece.\n", caster);
      
  caster->Defend(15,DT_ELECTRO,DEFEND_F_NOMSG|DEFEND_F_NOLIV);
  return 1;
}
