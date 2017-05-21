
/* SIMAURIA '/std/magia/esencia/piel_piedra.c'
   ===========================================
   [w] Woo@simauria

   25-11-99 [w] Conjuro de los conjuradores.
   27-01-99 [w] Cambiado el SetCombatDelay que tenia los argumentos al
                contrario y petaba.
   15-02-00 [w] Ahora solo te quedas rigido durante 1 segundo.
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <sounds.h>
inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())

create() {
  ::create();
  SetSpellName("Piel de Piedra");
  SetSpellUse("[contra <objetivo>]");
  SetSpellType(ST_PROTECT);
  SetSPCost(16);
  SetCastLevel(GC_CONJURADORES,1);
  SetMemorizeLevel(GC_CONJURADORES,12);
  SetTiredTime(1);
  SetSpellXP(10);
  SetSpellDescription("\
Cuando lanzas el conjuro la criatura afectada gana una protección virtual\n\
contra cualquier ataque por corte, golpe o semejante debido a que consigue\n\
un endurecimiento de la piel. Si no especificas a ninguna criatura el efecto\n\
del conjuro repercutirá en tí.\n");
}

mixed Check(object caster, string args) {
 string quien;
 object jugador;
 
 if (!sizeof(args))
 {
  jugador = caster;
  if (present("conjuro_piel_piedra",jugador))
   return notify_fail("Tu piel no resistiría el efecto de este conjuro por duplicado.\n");
  return caster;
 }

 if (sscanf(args,"contra %s",quien)!=1)
  return notify_fail("¿Contra quien quieres invocar el conjuro?\n");

 if (!jugador=present(quien,environment(caster)))
  return notify_fail("No puedes ver a "+quien+" aquí.\n");

 if (jugador==caster)
 {
  if (present("conjuro_piel_piedra",jugador))
   return notify_fail("Tu piel no resistiría el efecto de este conjuro por duplicado.\n");
  return jugador;
 }

 if (!living(jugador))
  return notify_fail("Este conjuro solo afecta a seres vivos.\n");

  if (present("conjuro_piel_piedra",jugador))
   return notify_fail("La piel de "+jugador->QueryName()+" no resistiría el efecto de este conjuro por duplicado.\n");

 return jugador;
}

int Cast(object caster, mixed jugador) {
 int tiempo;
 object magic_obj;

 tiempo = 30*caster->QueryGuildLevel();

 seteuid(getuid(TO));
 magic_obj=clone_object("/guilds/conjuradores/obj/piel_piedra");
 magic_obj->Endurecer(jugador, tiempo);

 if (caster==jugador)
 {
  write("Te concentras y tensas los musculos mientras "
   "pronuncias unas palabras. Una lluvia de polvo de granito y "
   "de polvo de diamante cae sobre tu cuerpo y notas como tu piel "
   "se endurece como la piedra.\n");

  say(capitalize(caster->QueryName())+" se concentra y tensa "
   "los musculos mientras pronuncia unas palabras. Una lluvia de polvo de "
   "granito y de polvo de diamante cae sobre su cuerpo y ves como su piel "
   "toma un tono muy especial.\n",({caster}));
 } else
 {
  write("Te concentras y miras fijamente a "+jugador->QueryName()+
   " mientras pronuncias unas palabras. Una lluvia de polvo de granito y "
   "de polvo de diamante cae sobre su cuerpo y notas como su piel "
   "toma un tono muy especial.\n");

  say(capitalize(caster->QueryName())+" se concentra y mira fijamente a "
   +jugador->QueryName()+
   " mientras pronuncia unas palabras. Una lluvia de polvo de "
   "granito y de polvo de diamante cae sobre el cuerpo de "+jugador->QueryName()+
   " y ves como su piel toma un tono muy especial.\n",({caster,jugador}));

  tell_object(jugador,capitalize(caster->QueryName())+" se concentra y te "
   "mira fijamente mientras pronuncia unas palabras. Una lluvia de polvo de granito "
   "y de polvo de diamante cae sobre tu cuerpo y notas como tu piel se endurece "
   "como la piedra.\n");
 }

 return 1;
}

int Fail(object caster, mixed mix) {
    play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));
    write("Te concentras y pronuncias unas palabras. Inesperadamente "
  "una lluvia de polvo de granito cae sobre tu cuerpo y notas como tus "
  "musculos se endurecen en demasia y te paraliza.\n");

 say(capitalize(caster->QueryName())+" se concentra y pronuncia "
  "unas palabras. Inesperadamente una lluvia de polvo de gramito cae sobre "
  "su cuerpo y ves como se queda rigid"+ART(caster)+" como una piedra.\n",({caster}));

 caster->SetCombatDelay(1,"Estás rigid"+ART(caster)+" como una piedra.\n");

 return 1;
}

