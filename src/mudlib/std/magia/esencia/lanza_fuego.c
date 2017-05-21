
/* SIMAURIA '/std/magia/esencia/lanza_fuego.c'
   ==============================================
   [w] Woo@simauria
   [m] Maler@simauria

   16-10-99 [w] Hechizo de los conjuradores.
   19-11-99 [w] Ahora primero le hace el Kill y luego el Defend.
   21-06-00 [w] Pues nada, el daño en vez de dividirlo entre 2 lo divido
   		entre 3.
   19-10-00 [m] Es mi primer hechizo, me baso en el lanza acida, a ve q sale
   19-10-00 [m] Chequeo de inteligencia al lanzar y alguna cosilla mas
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
  SetSpellName("Lanza de Fuego");
  SetSpellUse("contra <objetivo>");
  SetSpellType(ST_ACID);
  SetSPCost(15);
  SetCastLevel(GC_HECHICEROS,1);
  SetMemorizeLevel(GC_HECHICEROS,5);
  SetTiredTime(1);
  SetSpellXP(13);
  SetSpellDescription("Conjuras una lanza de fuego y la lanzas a tu enemigo.\n");
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


  write("Cierras los ojos, y tranquilamente piensas en fuego.\n");
  say(capitalize(caster->QueryName())+" cierra los ojos.\n", ({caster}));

  return enemigo;
}

int Cast(object caster, mixed enemigo) {
  int danyo;
  int acierto;

	acierto = caster->QueryGuildLevel();
	acierto = ((random(acierto)+random(acierto))>>2) + caster->QueryInt();
	if (acierto>100) acierto = 100;

 if (acierto<=15) 	danyo = TP->QueryInt() + acierto/4;
 else if (acierto<=60)	danyo = TP->QueryInt() + acierto/2;
 else 			danyo = TP->QueryInt() + acierto;

  write("Sientes un calor intenso en tu costado derecho. "
        "Abres los ojos y ves la fuente del calor: una lanza de fuego. "
        "Rápidamente lo lanzas contra "+enemigo->QueryName()+".\n");

  say("Sientes un calor intenso en la habitación y ves su fuente, "
      "una lanza de fuego que levita al lado de "+caster->QueryName()+". "
      "Con un movimiento vertiginoso abre los ojos y la arroja sobre "+enemigo->QueryName()+
      ".\n", ({enemigo,caster}));

  tell_object(enemigo, "Sientes un calor intenso en la habitación y ves su fuente, "
      "una lanza de fuego, que levita al lado de "+caster->QueryName()+". "
      "Con un movimiento vertiginoso abre los ojos y la arroja sobre ti.\n");

  if (TP->QueryInt()+random(20)>40) {
    write("Has conseguido crear una lanza superior.\n");
    danyo=danyo * 2;
  }
  if (TP->UseSkill(HAB_LANZAR,30)<0) {
     write("La lanza no impacta de lleno en tu enemigo.\n");
     danyo = danyo / 2;
  }

  if (danyo > (70+TP->QueryInt()) ) danyo=70+TP->QueryInt();
  enemigo->AddEnemy(TP);
  enemigo->Defend(danyo, TM_CALOR, DEFEND_SPELL);

  return 1;
}


int Fail(object caster, mixed enemigo) {
  play_sound(ENV(caster),SND_MAGIA("fallar.mp3"));

  write("No consigues encontrar tu fuego interno.\n");
  say(capitalize(caster->QueryName())+" abre los ojos.\n", ({caster}) );

  return 1;
}


