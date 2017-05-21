
#include "./path.h"

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("Gorat");
    SetIntShort("la calle principal de Gorat");
    SetIntLong("Esta es la calle principal del pueblo pesquero de Gorat. La calle "
  "es recta y larga, transcurre del oeste, donde se encuentra el puerto, hacia el este "
  "adentrándose en la localidad.\n");
    SetIndoors(0);
    AddExit("este","./callep2");
    AddExit("oeste", "./callep0");
    AddItem(GORPNJ("guard"), REFRESH_DESTRUCT, 1);
    AddItem(GORPNJ("guard2"), REFRESH_DESTRUCT, 1);
    AddItem(GORPNJ("ciudada2"), REFRESH_DESTRUCT, 1);
}
