/** Censo de Kha-annu
 * /d/kha-annu/comun/habitacion/kha-annu/ciudad/ayuntamiento/censo
 */

#include "./path.h"
inherit "/room/censo";

create() {
    ::create();

    SetCity("Kha-annu");

    SetLocate("Ciudad de Kha-annu");
    SetIntShort("el censo de la capital de Kha-annu");
    SetIntLong("Te encuentras en el censo de la ciudad de Kha-annu, donde te puedes hacer "
               "Ciudadano de esta noble capital, aqui se encuentra el bueno de Gorin, "
               "responsable de la oficina del censo, si quieres informacion preguntale.\n");

    SetIntBright(50);

    SetIndoors(1);

    AddExit("sur", "./ayun1");

    AddItem(MONS+"censador",REFRESH_DESTRUCT,1);
}
