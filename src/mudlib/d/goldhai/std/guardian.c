/*=============================================================*
 |            << GOLDHAI.Crowy [w] Woo@simauria >>             |
 *=============================================================*
 |               Creacion............. 20-04-99                |
 |               Ultima Modificacion.. 28-10-99                |
 |                                                             |
 | 28-10-99 [w] Corregido un ligero error con Die()            |
 *=============================================================*/

#include "../path.h"
#include <wizlevels.h>
#include <moving.h>

#define ASESINOS DOM_STD "asesinos"

inherit NPC;

init()
{
 mixed *enemigos;
 int i;
 ::init();

 if (!TP->QueryIsPlayer())
  return;
 if (IS_LEARNER(TP))
  return;

 enemigos=TP->QueryEnemies();
 if (enemigos)
 {
  if(sizeof(enemigos))
   for(i=0;i<sizeof(enemigos);i++)
    if(enemigos[i]->QueryCrowiano())
    { Kill(TP); return; }
 }

 if (ASESINOS->AsesinoPresente(LOWER(TNREAL)))
  if (ASESINOS->peligrosidad(LOWER(TNREAL)) > 401)
  {
   Kill(TP);  // [w] Si es peligroso le atacara
   return;
  }

 return;
}

public int QueryCrowiano()
{
 return 1;
}

public int QueryGuardian()
{
 return 1;
}

private status existe_jugador(string jugador) {
 return find_savefile(jugador)||find_object(lower_case(jugador));
}


private int IsGuardian(object mon)
{
 if(mon->QueryGuardian() && mon!=TO)
  return 1;
 return 0;
}

move(dest,method,stuff) // No puede salir de crowy
{
 if((method==M_GO && dest->QueryLocate()!="crowy") || (method==M_GO && TO->QueryEnemies()!=({})))
  return ME_NO_ENTER;
 return ::move(dest,method,stuff);
}

DoDamage(int dmg) // Si le atacan busca a los guardias para que le defiendan.
{
 int i;
 object *guardias;

 guardias = filter(deep_inventory(environment(TO)),SF(IsGuardian));

 if(sizeof(guardias))
  for(i=0;i<sizeof(guardias);i++)
   guardias[i]->Kill(TP || PO);

 return ::DoDamage(dmg);
}

public varargs void Die(mixed silent) {
 object ASESINO;

 ASESINO=PO;
 if (!ASESINO->QueryIsPlayer()) {return ::Die(silent);}
 if(!existe_jugador(ASESINO->QueryRealName())) {return ::Die(silent);}
 ASESINOS->SetAsesino(ASESINO->QueryRealName(),2,1,0,1);
 ::Die(silent);
}
