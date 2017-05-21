
#include "./path.h"

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("puerto de Gorat");
    SetIntShort("el faro de Gorat");
    SetIntLong(
    "Te encuentras en la entrada del faro de gorat, es un faro viejo "
    "y algo oxidado, pero sirve para que los barcos no se estrellen "
    "en las escarpadas rocas que bordean el pueblo de Gorat. "
    "Hay unas escaleras para subir a la parte alta del faro donde está la lente, y fuera "
    "tienes la playa.\n");
    SetIntBright(30);
    SetIntNoise("Se escucha el rumor del mar.\n");
    SetIntSmell("Aquí dentro también huele a mar.\n");
    AddItem(GORPNJ("farero"),REFRESH_DESTRUCT);
    AddExit("arriba","./faro2");
    AddExit("fuera","../playa/playa2");
    }
