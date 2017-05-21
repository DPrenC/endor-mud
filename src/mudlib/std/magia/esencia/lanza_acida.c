
/* SIMAURIA '/std/magia/mentalismo/lanza_acida.c'
   ==============================================
   [w] Woo@simauria

   16-10-99 [w] Hechizo de los conjuradores.
   19-11-99 [w] Ahora primero le hace el Kill y luego el Defend.
   21-06-00 [w] Pues nada, el daño en vez de dividirlo entre 2 lo divido
   		entre 3.
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <moving.h>
#include <skills.h>
#include <sounds.h>
inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())

create() {
  ::create();
  SetSpellName("Lanza de Acido");
  SetSpellUse("contra <objetivo>");
  SetSpellType(ST_ACID);
  SetSPCost(10);
  SetCastLevel(GC_CONJURADORES,1);
  SetMemorizeLevel(GC_CONJURADORES,7);
  SetTiredTime(1);
  SetSpellXP(13);
  SetSpellDescription("Conjuras una lanza de ácido y la lanzas a tu enemigo.\n");
 }

mixed Check(object caster, string args) {
  string quien;
  object enemigo;

  if (!sizeof(args) || sscanf(args,"contra %s", quien)!=1)
    return notify_fail("¿Contra quién quieres lanzar el conjuro?\n");

  if (!enemigo=present(quien, environment(caster)))
    return notify_fail("No puedes ver a "+quien+" aquí.\n");

  if (!living(enemigo))
    return notify_fail("No creo que a eso le afecte mucho.\n");

  if(enemigo==caster)
    return notify_fail("¿Quieres suicidarte?\n");

  if (!CanCastSpell(enemigo)) return 0;

  return enemigo;
}

int Cast(object caster, mixed enemigo) {
  int danyo;
  int acierto;

	acierto = caster->QueryGuildLevel();
	acierto = ((random(acierto)+random(acierto))>>2) + caster->QueryInt();
	if (acierto>100) acierto = 100;

  if (acierto<=15) danyo = caster->QueryInt() + acierto/4;
  else if (acierto<=60) danyo = caster->QueryInt() + acierto/2;
  else danyo = caster->QueryInt() + acierto;

	if (danyo > (50+caster->QueryInt() ) ) danyo=50+caster->QueryInt();

	write("Extiendes un brazo y lo elevas por encima de tu cabeza. Te concentras "
    "y consigues crear una lanza de ácido que instantáneamente lanzas contra "+enemigo->QueryName()+
    ".\n");

  say(capitalize(caster->QueryName())+" extiende un brazo y lo eleva por encima de su "
    "cabeza, se concentra y aparece en su mano una lanza de ácido que instantáneamente "
    "lanza contra "+enemigo->QueryName()+
    ".\n",({enemigo,caster}));

  tell_object(enemigo,capitalize(caster->QueryName())+" extiende un brazo y lo eleva por encima de su "
    "cabeza, se concentra y aparece en su mano una lanza de ácido que instantáneamente te lanza con fuerza.\n");

  if (caster->UseSkill(HAB_LANZAR,30)<0) {
     write("La lanza no impacta de lleno en tu enemigo.\n");
     danyo = danyo / 2;
  }

  enemigo->AddEnemy(caster);
  enemigo->Defend(danyo, TM_ACIDO, DEFEND_SPELL);
    play_sound(ENV(caster),SND_MAGIA("lanzaacido.mp3"));

  return 1;
}

int Fail(object caster, mixed enemigo) {
  object piedra;

  play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));
  write(W("Extiendes un brazo y lo elevas por encima de tu cabeza. Te concentras "
    "y consigues crear una.. ¿una piedra? Creo que has fallado miserablemente el conjuro.\n"));

  say(W(capitalize(caster->QueryName())+" extiende un brazo y lo eleva por encima de su "
    "cabeza, se concentra y aparece en su mano una bonita piedra de color rojo.\n"),({caster}));

  seteuid(getuid(TO));
  piedra=clone_object("/std/thing");
  piedra->SetShort("una piedra roja");
  piedra->SetLong("Es una piedra de color rojo.\n");
  piedra->AddAdjective(({"magica","mágica","roja"}));
  piedra->AddId("piedra");
  piedra->SetValue(0);
  piedra->SetWeight(400);
  seteuid(0);

  if(piedra->move(caster) != ME_OK)
  {
    write("No puedes cargar con la piedra.\n");
    piedra->move(environment(caster),M_DROP);
    return 1;
  }

 return 1;
}


