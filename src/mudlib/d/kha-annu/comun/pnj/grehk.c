/* Creado por [I] Izet@Simauria.
   Cuidador del tablon de la Escuela de Metalurgia.
   [Woo] Modificado
*/

#include "path.h"
#include <guild.h>
#define NAME TP->QueryName()

inherit KBASE;

create() {
      ::create();
  SetStandard("Thror","enano",([GC_LUCHADOR: 10]),GENDER_MALE);
  SetShort("Thror, el forjador");
  SetLong(
"Thror es un antiguo oficial de la guardia de Kha-annu. Aprendió a tratar los\n"
"metales en muchos de sus viajes a pueblos extranjeros, y tiene conocimientos\n"
"de todos los metales y aleaciones posibles.\n"
);
  SetAggressive(0);
  SetAlign(200);
  SetIds(({"enano","herrero","el herrero","al herrero","al enano","el enano"}));
  InitAChats(8,({
   "Thror grita: ¡Pagarás cara tu osadia bellaco! ¡¡¡A mi la guardia!!!\n"
  }));

}

public varargs void Die(mixed silent) {
   tell_room(environment(TO),
    "Thror dice: "+NAME+", no escaparás con vida de esta ciudad... *atjo! atjo!*\n");
    TP->SetAttribute("asesino",(TP->QueryAttribute("asesino"))+1);
    ::Die(silent);
}
