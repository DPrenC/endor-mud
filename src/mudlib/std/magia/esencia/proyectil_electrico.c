
/* SIMAURIA '/std/magia/esencia/proyectil_electrico.c'
   ==============================================
   [m] Maler@simauria

   21-10-00 [m] Hechizo de los conjuradores.
*/

#include <ts.h>
#include <magia.h>
#include <guild.h>
#include <moving.h>
#include <skills.h>
#include <combat.h>
#include <sounds.h>
inherit STD_SPELL;

#define ART(x)   (x->QueryGenderEndString())

create() {
  ::create();
  SetSpellName("Proyectil electrico");
  SetSpellUse("contra <objetivo>");
  SetSpellType(ST_ELECTRO);
  SetSPCost(25);
  SetCastLevel(GC_HECHICEROS,8);
  SetMemorizeLevel(GC_HECHICEROS,15);
  SetTiredTime(1);
  SetSpellXP(17);
  SetSpellDescription("Creas un rayo que impacta a tu enemigo.\n");
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
    int danyo, rayo;
    int acierto;

	acierto = caster->QueryGuildLevel();
	acierto = ((random(acierto)+random(acierto))>>2) + caster->QueryInt();
	if (acierto>100) acierto = 100;

    rayo = 1;
    if (acierto<=15) 	danyo = caster->QueryInt() + acierto/3;
    else if (acierto<=60)	danyo = caster->QueryInt() + acierto*2/3;
    else 			danyo = caster->QueryInt() + acierto*4/3;

  write(W("Apuntas con tu dedo índice a tu enemigo y pronuncias las palabras del hechizo:\n"
    "Dices: Creil Uz Tirôm.\n"
    "Al momento un rayo sale de tu dedo hacia "+capitalize(enemigo->QueryName())+
    ".\n"));

  say(capitalize(caster->QueryName())+" apunta su dedo índice hacia "+enemigo->QueryName()+"y pronuncia unas palabras.\n"+
    capitalize(caster->QueryName())+" dice: Creil Uz Tirôm.\n"
    "Al momento un rayo sale de su dedo hacia "+capitalize(enemigo->QueryName())+
    ".\n",({enemigo,caster}));

  tell_object(enemigo,capitalize(caster->QueryName())+" apunta su dedo índice hacia ti y pronuncia unas palabras.\n"+
    capitalize(caster->QueryName())+" dice: Creil Uz Tirôm.\n"
	"Al momento un rayo sale de su dedo y se dirige hacia ti.\n");

  if (caster->QueryInt()+random(20)>40) {
    rayo = 2;
    write("Creas un rayo bifurcado que impacta a tu enemigo dos veces!!.\n");
    say(capitalize(caster->QueryName())+" crea un rayo bifurcado que impacta en "+
        capitalize(enemigo->QueryName())+" dos veces!\n",({enemigo,caster}));
    tell_object(enemigo,capitalize(caster->QueryName())+" crea un rayo bifurcado que te "
        "impacta dos veces!\n");
    danyo=danyo * 2;
  }

  if (danyo > (100+caster->QueryInt()) ) danyo=100+caster->QueryInt();
    play_sound(ENV(caster),SND_MAGIA("proyectil.mp3"),0,100,rayo);
  enemigo->AddEnemy(caster);
  enemigo->Defend(danyo*2, TM_ELECTRICIDAD, DEFEND_SPELL);

  return 1;
}

int Fail(object caster, mixed enemigo) {
  play_sound(ENV(caster),SND_MAGIA("fallarproyectil.mp3"));
  write(W("Apuntas tu dedo hacia tu enemigo y comienzas a pronunciar el hechizo, pero se te traba la lengua y fallas.\n"));

  say(W(capitalize(caster->QueryName())+" apunta con su dedo a "+enemigo->QueryName()+" pero nada pasa.\n"),({caster}));
 return 1;
}


