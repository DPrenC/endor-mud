/* Creado por [I] Izet@Simauria.
   Ratas debiluchas para newbies.
   Modificada por gorthem para hacer ratoncillos
   [Woo] Modificado
*/


#include "path.h"
#include <moving.h>
inherit NPC;


create() {
      ::create();
  SetStandard("un ratoncillo","roedor",1,0);
  SetShort("Un ratoncillo");
  SetLong(
"Es un pequeño ratón de color grisaceo. Tiene pequeños dientes, y parece estar\n"
"buscando restos de comida.\n");
  SetAggressive(0);
  SetAlign(0);
  SetMaxHP(10);
  SetHP(10);
  SetAC(0);
  SetWhimpy(0);
  SetHands( ({ ({"los colmillos",1,0}), ({"los colmillos",1,0}) }) );
SetIds(({"ratón","ratón gris","raton","un raton","la rata","raton gris","un raton gris","el raton gris"}));
  InitAChats(8,({
   "El ratoncillo se pone sobre las patas traseras amenazadoramente.\n",
   "El ratoncillo se lanza contra ti, dando una vuelta en el aire.\n"
  }));

}

public varargs void Die(mixed silent) {
    tell_room(environment(TO),
"El ratoncillo cae muerto al suelo.\n"
);
   ::Die(silent);
}

move(dest,method,stuff) // No puede salir de Kha-annu
{
 if(method==M_GO && dest->QueryLocate()!="Kha-annu")
    return ME_NO_ENTER;
        return ::move(dest,method,stuff);
}

