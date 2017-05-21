#include "../sys/asesinos.h"

#include <combat.h>

#define COMMAND_NAME	HAB_ACUCHILLAR
#define COMMAND_NAME_EXTRA	HAB_CUTTHROAT
#define MANA_COST 	MANA_ACUCHILLAR
#define MANA_EXTRA	(MANA_CUTTHROAT-MANA_ACUCHILLAR)

main(string str) {
int check, bonus, i;
object atk, def=0, *armas;
mixed arma=0;
string str2;

  seteuid(getuid());

  atk=TP;
  str2=str;
//if(find_object("nyh")) dtell("nyh",sprintf("Acuchillar "+str+".\n"));
  if (atk->HasSkill(COMMAND_NAME) != 1)
      return notify_fail(W("No posees la habilidad "+COMMAND_NAME+".\n"));
  if(sizeof(atk->QueryEnemies())) {
    if (atk->Query(COMBATACTION_FINTAR)) {
      atk->Set(COMBATACTION_FINTAR,0);
      def = atk->QueryEnemy();
    }
    else return notify_fail(W("¡No puedes hacer eso mientras estás en combate!\n"));
  }
  if (!def) {
    if (!str) return notify_fail(W("¿Acuchillar a quién?\n"));
    if (sscanf(str,"a %s",str2)==1) str=str2;
    if(!(def=present(str,environment(atk))))
      return notify_fail(W("No ves a "+capitalize(str)+" a tu alrededor.\n"));
  }
  if(!present(def,environment(atk)))
    return notify_fail(W("No ves a "+capitalize(def->QueryName())+" a tu alrededor.\n"));
  if(!living(def))
    return notify_fail(W("¡Eso seria tremendamente efectivo!\n"));
  if(def==atk)
    return notify_fail(W("Mejor prueba el comando 'suicidar'.\n"));
//  if(!IS_HUMANOID(def))
//      return notify_fail(W("No puedes apuñalar criaturas no humanoides.\n"));
  if (def->Query(P_CANT_FIGHT) & C_NORMAL_FIGHT)
    return notify_fail(W("No puedes atacar a "+capitalize(str)+".\n"));
  if (def->QueryChkFightFunction() && !funcall(def->QueryChkFightFunction(), TP)) return 0;
  if (environment(def)->QuerySafe())
    return notify_fail(W("No puedes atacar aqui.\n"));
  if (check=sizeof(armas=atk->QueryWeapons()||({}))) {
    for(i=0;i<check;i++) //lo miro en orden creciente
      if ( (armas[i]->QueryDamageType()==TD_PENETRACION))
        { arma = armas[i]; break; }
  } //si no tiene arma valida quiza un arma natural valida...
  if (!arma && (check = sizeof(armas=(atk->QueryHands()||({})))) ) {
    for(i=0;i<check;i++) //lo miro en orden creciente
      if (armas[i][HAND_WEAPON]==TD_PENETRACION) {
      	arma=i+1; //le sumo 1 para que la mano 0 de 1, acordarse!!!
      	break;
      }
  }
  if(!arma) return notify_fail(W("Deberás tener un arma penetrante para poder acuchillar.\n"));
  if (intp(arma)) arma--; //porq antes le he sumado 1...
  if((time()-atk->Query("_last_backstab"))<TIMER_ACUCHILLAR)
     return notify_fail(W("Tendrás que esperar un tiempo para poder volver a acuchillar.\n"));
  if(NO_MANA(atk))
     return notify_fail(W("No tienes suficientes puntos de magia.\n"));
  if (!query_wiz_level(TP) && query_once_interactive(def))
  // PK?
  {
    seteuid(getuid());
    log_file("TRY_PK", ctime() + ". " + TNREAL + " intentó acuchillar a " + NREAL(def) + ".\n");
    return notify_fail("La lucha entre jugadores no está permitida.\n");
  }
  atk->AddSP(-MANA_COST);

  bonus = BONUS_SNEAK;
  check = atk->UseSkill(COMMAND_NAME, atk->QueryGuildLevel()+atk->QueryDex()-def->QueryInt(),1);
  if (atk->HasSkill(COMMAND_NAME_EXTRA) && atk->UseSkill(COMMAND_NAME_EXTRA,0,1)>0)
       bonus += atk->QueryGuildLevel()*10;
  else bonus += atk->QueryGuildLevel()*5;
//  if (find_object("nyh")==atk) dtell("nyh",sprintf("Attack->(%O,%O,%i,%i,%i)\n",arma, def, check, BONUS_SNEAK, ATTACK_SNEAK));
  COMBATMASTER->Attack(atk, def, arma, check, bonus, ATTACK_SNEAK);

  atk->Set("_last_backstab",time());
  //LOG("ACUCHILLAR","["+OWNER->QueryGuildLevel()+"]"+capitalize(OWNER->QueryRealName())+"\t Skill: "+atk->QuerySkillLevel(COMMAND_NAME)+"Check: "+check+" Daño: "+da);
  return check||-1;
}
