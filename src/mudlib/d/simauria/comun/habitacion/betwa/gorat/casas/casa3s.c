
#include "./path.h"

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("Gorat");
    SetIntShort("una casa de Gorat");
    SetIntLong(
    "est�s en una casa de pescadores, como tantas otras de este pueblo.\n "
    "Esta casa es de las m�s peque�as, pues s�lo tiene una estancia, con lo que "
    "poca gente puede vivir aqu�.\n");
    SetIntBright(30);

    AddExit("norte","../calles/callep3");
    AddDoor("norte", "la puerta de la calle");
    }
