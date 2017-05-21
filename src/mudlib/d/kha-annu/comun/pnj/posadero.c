/* Creado por [I] Izet@Simauria.
  Modificado por [Y] Yandros
  [Woo] Modificado
*/

#include "path.h"
#include <properties.h>

inherit KBASE;

create() {
   ::create();
  SetStandard("Ashurak","enano",20,GENDER_MALE);
  SetShort("Ashurak, el posadero");
  SetLong(
"Ashurak es el duenyo de la Posada del Dragon Rojo. Tiene una cicatriz en su\n"
"mejilla izquierda aunque no tiene pinta de ser peligroso. Su trabajo consiste en\n"
"administrar las habitaciones de la posada y mantener un ambiente tranquilo.\n");
  SetAggressive(0);
  SetWeight(55000);
  SetStr(18);
  SetDex(15);
  SetInt(24);
  SetCon(20);
  SetHP(202);
  SetAlign(230);
  SetWhimpy(0);
  SetHands( ({ ({"el puño derecho",0,1}), ({"el puño izquierdo",0,1}) }) );
  SetIds(({"ashurak","posadero","ashurak el posadero","encargado"}));
   seteuid(getuid(TO));
   AddItem("/obj/money",REFRESH_REMOVE,(["Money":(["oro":random(40),"plata":random(10) ]) ]) );

}

public varargs void Die(mixed silent) {
    tell_room(environment(TO),
"Ashurak pierde el equilibrio y cae al suelo totalmente muerto.\n"
);
   ::Die(silent);
}
