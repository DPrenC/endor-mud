/* SIMAURIA '/guilds/guardabosques/pnj/special/special'
   ====================================================
   [t] theuzifan

   xx-xx-xx [t] Creación.
   15-05-02 [t] Arreglados multiples fallos
   21-05­02 [t] Si el creador del animal decide atacarlo, que éste no se
   		siga a si mismo...
*/

#include <living.h>
#include <properties.h>
#include "path.h"

inherit "/std/npc";

#define NUMCALL "_numcall"
private object follows_to;

object FollowsTo(object ob, int perc)
{
  int time;
  follows_to=ob;

  ob->AddFollower(TO);
  ob->Set(NUMCALL, ob->Query(NUMCALL) + 1);

  time = perc * 2;
  if (time < 25) {
  	time = 25;
  }
  call_out("remove", time);
  return ob;
}

create()
{
  ::create();
  SetStandard("un animal", "animal", 0, GENDER_NEUTER);
  SetShort("un animal");
  SetLong("Es un animal.\n");
  SetWhimpy(0);
  set_heart_beat(1);
}

heart_beat()
{
  int i;
  object *enemies;

  ::heart_beat();

  if (!follows_to) return;
  enemies=follows_to->QueryEnemies() || ({});

  for (i=0; i<sizeof(enemies); i++)
  {
    if (enemies[i] == TO) {
    	follows_to->SetAlign(follows_to->QueryAlign() - 5);
    	continue;
    }
    Kill(enemies[i]);
//    follows_to->RemoveFollower(TO);
//    enemies[i]->AddFollower(TO);
  }
}
remove() {
	if (follows_to) {
		follows_to->Set(NUMCALL, follows_to->Query(NUMCALL) - 1);
		follows_to->RemoveFollower(TO);
		
		if (!follows_to->Query(NUMCALL)) {
			tell_object(follows_to, "Acaba tu control mental sobre los animales convocados.\n");
		}
	}
	::remove();
}
