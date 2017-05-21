/* Creado por [I] Izet@Simauria.
  Modificado por [Y] Yandros
  [Woo] Modificado
*/


#include "path.h"
#include <properties.h>

inherit KBASE;


create() {
      ::create();

  SetStandard("Yako","enano",25,GENDER_MALE);
  SetShort("Yako, el herrero");
  SetLong(
"Es un enano corpulento con una notable cresta de color naranja. Sus brazos estan\n"
"llenos de tatuajes y lleva una argolla en la nariz y varias en las orejas.\n");
  SetAggressive(0);
  SetWeight(70000);
  SetStr(27);
  SetDex(23);
  SetInt(18);
  SetCon(32);
  SetAlign(100);
  SetWhimpy(0);
  SetHands( ({ ({"el puño derecho",0,2}), ({"el puño izquierdo",0,1}) }) );
  SetIds(({"yako","yako el herrero","herrero","enano"}));
   seteuid(getuid(TO));
   AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["oro":random(40),"plata":random(10) ]) ]) );
  InitChats(1,({
   "Yako murmura: Algún dia los orcos volverán y entonces estaré preparado.\n",
  "Yako dice: Mis primos y yo fuimos grandes guerreros cuando luchamos por el\n"
   "dominio de estas montañas.\n",
  }));

}

public varargs void Die(mixed silent) {
    tell_room(environment(TO),
"Yako se resiste a morir y dobla las rodillas antes de caer definitivamente muerto.\n"
);
   ::Die(silent);
}
