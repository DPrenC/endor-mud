/* Creado por [I] Izet@Simauria.
   Cuidador del tablon de la Escuela de Metalurgia.
   [Woo] Modificado
*/


#include "path.h"
#include <properties.h>
#define NAME TP->QueryName()

inherit KBASE;


create() {
  ::create();
  SetStandard("Shalok","enano",1,GENDER_MALE);
  SetShort("Shalok, el ingeniero");
  SetLong(
"Ves a Shalok. Shalok es un enano debilucho con pinta de empollon. Cada vez,\n"
"que lo miras aparta la vista hacia un marco que hay colgado en la pared y que\n"
"tiene su nombre; parece ser su titulo de ingenieria... seguro que esta muy\n"
"orgulloso de el.\n");
  SetAggressive(0);
  SetInt(5);
  SetAlign(200);
  SetMaxHP(20);
  SetHP(20);
  SetAC(1);
  SetIds(({"enano","ingeniero","el ingeniero","al ingeniero"}));
  SetAds(({"un","debilucho","flacucho","debil","flaco"}));
  InitAChats(8,({
   "Shalok gime: ¡Por favor, no me mates! ¡Solo soy un pobre ingeniero!\n"
  }));

}

public varargs void Die(mixed silent) {
    tell_room(environment(TO),
"Shalok cae al suelo de frente, y sus gafas se le rompen en los ojos.\n"
"Los cristales se incrustan en las orbes oculares de Shalok mientras su alma\n"
"abandona su cuerpo sin vida.\n");
   ::Die(silent);
}
