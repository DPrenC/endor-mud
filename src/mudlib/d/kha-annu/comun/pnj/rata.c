/* Creado por [I] Izet@Simauria.
   Ratas debiluchas para newbies.
*/


#include "path.h"
#include <properties.h>

inherit NPC;


create() {
      ::create();
  SetStandard("una rata","roedor",1,GENDER_FEMALE);
  SetShort("una rata");
  SetLong(
"Es una enorme rata de color gris. Tiene colmillos afilados, y parece estar\n"
"oliendo algo.\n");
  SetAggressive(0);
  SetAlign(0);
  SetMaxHP(10);
  SetHP(10);
  SetAC(0);
  SetWhimpy(0);
  SetGoChance(100);
  SetHands( ({ ({"los colmillos",1,1}), ({"las patas",0,1}) }) );
SetIds(({"rata","una rata","la rata","rata gris","una rata gris","la rata gris"}));
  InitAChats(8,({
   "La rata se pone sobre las patas traseras amenazadoramente.\n",
   "La rata se lanza contra ti, dando una vuelta en el aire.\n"
  }));

}

public varargs void Die(mixed silent) {
    tell_room(environment(TO),
"La rata golpea el suelo con su cuerpo mutilado.\n"
);
   ::Die(silent);
}
