/* SIMAURIA '/std/magia/mentalismo/maza_infernal.c'
   ================================================
   [w] Woo@simauria

   16-10-99 [w] Conjuro de los conjuradores.
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <moving.h>
#include <sounds.h>
inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())
#define MAZA     "/guilds/conjuradores/obj/maza_infernal"

private object enemigo;

create() {
  ::create();
  SetSpellName("Maza del Infierno");
  SetSpellUse("");
  SetSpellType(ST_CREATE);
  SetSPCost(20);
  SetCastLevel(GC_CONJURADORES,1);
  SetMemorizeLevel(GC_CONJURADORES,10);
  SetTiredTime(2);
  SetSpellXP(15);
  SetSpellDescription(
"Creas por un tiempo limitado la poderosa Maza del Infierno. Esta arma causa\n\
un mayor daño a todos los seres de alineamiento positivo.\n");
 }

int Cast(object caster, mixed mix) {
 int tiempo;
 object maza;

  tiempo = 30*caster->QueryGuildLevel();

  write("Invocas a los señores de las tinieblas para que te acepten como un fiel servidor. "
    "Al instante notas como una fuerza fluye por tu cuerpo y aparece una poderosa maza.\n");

  say(capitalize(caster->QueryName())+" mira al suelo e invoca a los señores de la tinieblas. "
    "Seguidamente una brillante luz ilumina el lugar y ves como "+capitalize(caster->QueryName())+
    " crea una poderosa maza.\n",({caster}));

  seteuid(getuid(TO));
  maza=clone_object(MAZA);
  maza->CalcPower(tiempo);
  if(maza->move(TP) != ME_OK)
  {
    write("No puedes cargar con la maza.\n");
    maza->move(environment(TP),M_DROP);
    return 1;
  }

  return 1;
}


int Fail(object caster, mixed mix) {
  play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));
  write("Invocas a los señores de las tinieblas para que te acepten como un fiel servidor "
          "pero parece que no te prestan mucha atención.\n");

  say(capitalize(caster->QueryName())+" invoca a los señores de las tinieblas pero nada ocurre.\n",({caster}));

 return 1;
}


