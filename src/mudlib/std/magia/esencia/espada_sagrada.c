/* SIMAURIA '/std/magia/esencia/espada_sagrada.c'
   ==============================================
   [w] Woo@simauria

   06-03-00 [w] Conjuro de los conjuradores.
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <moving.h>
#include <sounds.h>
inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())
#define ESPADA   "/guilds/conjuradores/obj/espada_sagrada"

private object enemigo;

create() {
  ::create();
  SetSpellName("Espada Sagrada");
  SetSpellUse("");
  SetSpellType(ST_CREATE);
  SetSPCost(40);
  SetCastLevel(GC_CONJURADORES,15);
  SetMemorizeLevel(GC_CONJURADORES,30);
  SetTiredTime(1);
  SetSpellXP(15);
  SetSpellDescription(
"Creas por un tiempo limitado una espada sagrada. Esta arma causa un\n\
mayor daño a todos los seres de alineamiento negativo.\n");
 }

int Cast(object caster, mixed mix) {
  int tiempo;
  object espada;

  tiempo = 30*caster->QueryGuildLevel();

  write("Invocas al Cielo para que te acepten como defensor del Bien. "
    "Inmediatamente aparece una espada sagrada.\n");

  say(capitalize(caster->QueryName())+" mira al cielo y dice unas palabras. "
    "Seguidamente una brillante luz ilumina el lugar y ves como "+capitalize(caster->QueryName())+
    " crea una espada.\n",({caster}));

  seteuid(getuid(TO));
  espada=clone_object(ESPADA);
  espada->CalcPower(tiempo);
  if(espada->move(TP) != ME_OK)  {
    write("No puedes cargar con la espada.\n");
    espada->move(environment(TP),M_DROP);
    return 1;
  }

  return 1;
}


int Fail(object caster, mixed mix) {
  play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));
  write("Invocas al Cielo para que te acepten como defensor del Bien "
          "pero parece que no te prestan mucha atención.\n");

  say(capitalize(caster->QueryName())+" mira al cielo y dice unas palabras.\n",({caster}));

 return 1;
}


