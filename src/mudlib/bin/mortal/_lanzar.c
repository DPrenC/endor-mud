/* 10/2012 adaptado a endor-mud */

#include <properties.h>
#include <combat.h>
#include <wizlevels.h>
#include <skills.h>
#include <moving.h>

lanzar(string str) {
  int i, acierto;
  string a, b;
  object que, quien;

  if (TP->QueryGuild() == GC_ASESINO) return 0; // los asesinos usan el lanzar de su gremio
  if (!TP->HasSkill(HAB_LANZAR)) return notify_fail("No tienes esa habilidad.\n");
  if (!str) return notify_fail("¿Lanzar qué contra quien?\n");
  if ( (sscanf(str,"%s contra %s",a,b)!=2) && (sscanf(str,"%s a %s",a,b)!=2) && (sscanf(str,"%s %s",a,b)!=2) )
    return notify_fail("¿Lanzar qué contra quien?\n");
  if (TP->QueryStunned() || TP->QueryCombatDelay())
    return notify_fail("Meditas sobre tus posibilidades de acierto.\n");

  que = present(a, TP);
  quien = present(b, environment(TP));

  if (!que) return notify_fail("No parece que tengas "+a+" a mano.\n");
  if (!quien) return notify_fail(b+" no está a la vista.\n");
  if (environment(TP)->QuerySafe()) return notify_fail("Este no es un buen lugar para lanzamientos.\n");
  if (quien->Query(P_CANT_FIGHT)) return notify_fail("No debes agredir a "+b+".\n");
  if (quien->Query(P_INVIS)>TP->Query(P_SEE_INVIS) ) quien=0;
  if (quien->Query(P_HIDDEN)>TP->Query(P_SEE_INVIS)
     && (member(quien->QuerySeenBy(),TP)==-1)) quien=0;

  if (IS_LEARNER(quien)) return notify_fail("No debes agredir a los ainur.\n");
  if (que->QueryGuildObject()) return notify_fail("Ese objeto es importante para tu personaje, no debes perderlo.\n");
  if (que->QueryNoDrop()) return notify_fail("No puedes lanzarlo.\n");
  if (que->QueryNoGive()) return notify_fail("No puedes lanzarlo.\n");
  if (quien == TP) return notify_fail("¿Quieres lanzártelo a tí?\n");
  if (TP->QueryCombatDelay()) return notify_fail(TP->QueryCombatDelayMsg());
  seteuid(getuid());
  COMBATMASTER->Attack(TP, quien, que, 0, 0, ATTACK_THROW);
  que->move(environment(TP),M_SILENT);
  TP->SetCombatDelay(1,"Recuperas la posición óptima.\n");


  return 1;
}
