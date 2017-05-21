#include "../sys/asesinos.h"

#include <combat.h> //COMBATACTION_FINTAR

#define COMMAND_NAME	HAB_FINTAR
#define MANA_COST 	MANA_FINTAR

main(string str) {
  int ene;
  object atk;

  seteuid(getuid());

  atk = TP;

  if (atk->HasSkill(COMMAND_NAME) != 1)
    return notify_fail(W("No posees la habilidad "+COMMAND_NAME+".\n"));
  if(!(ene=sizeof(atk->QueryEnemies())))
    return notify_fail(W("Necesitas estar en combate para poder hacer eso.\n"));
  if(NO_MANA(atk))
     return notify_fail(W("No tienes suficientes puntos de magia.\n"));
  atk->AddSP(-MANA_COST);
  atk->AddCombatAction(COMBATACTION_FINTAR);
  write("Te preparas para realzar una finta.\n");

  return 1;
}
