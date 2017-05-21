/* Creado por [I] Izet@Simauria.
   Slugs. Especie de babosas que escupen acido.
*/


#include "path.h"
#include <properties.h>

inherit NPC;


create() {
      ::create();
  SetRace("animal");
  SetName("slug");
  SetShort("un slug");
  SetLong(
"Ves una especie de masa viscosa de color verde brillante. Parece peligrosa...\n"
);
   SetAlign(-500);
  SetGender(GENDER_NEUTER);
  SetAggressive(1);
  SetLevel(2);
  SetAlign(-20);
  SetAC(0);
  SetWhimpy(0);
  SetGoChance(0);
  SetHands( ({ ({"tentaculo izquierdo",1,1}),({"tentaculo derecho",1,1}) }) );
SetIds(({"slug","babosa","masa","masa viscosa"}));
SetAds( ({"un","el","una","la"}) );
  InitAChats(8,({
   "El slug retrocede acobardado, dejando un rastro viscoso tras de si.\n",
   "Golpeas al slug en su tentaculo derecho y un liquido amarillento sale de el.\n"
  }));

}

public varargs void Die(mixed silent) {
    tell_room(environment(TO),
"El slug se derrite por completo, y el suelo absorbe el liquido verdoso.\n"
);
   if(TO) destruct(TO);
}
