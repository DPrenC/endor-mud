/*
casa del quest de gorat
cheto 10-10-2001
*/

#include "./path.h"

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("Gorat");
    SetIntShort("la casa del registro");
    SetIntLong(
    "Te encuentras en la entrada del registro civil del pueblo pesquero "
    "de Gorat. En esta casa puedes conseguir el impreso JK23-H, el Carnet "
    "Oficial de Reparador de Faros de Simauria.\nTienes al norte un pasillo "
    "en el que puedes ver puertas a ambos lados y al sur la salida del edificio.\n");
    AddExit("norte","./pasillo11");
    AddExit("sur","../calles/callep0");
    AddDoor("sur", "la puerta de la calle",
    "Es la puerta de salida a la calle principal de Gorat.\n",
    ({"puerta", "puerta del sur", "puerta principal", "puerta de salida",
        "puerta de la calle"}));
    AddItem(GORPNJ("guard"), REFRESH_DESTRUCT,2);
}
