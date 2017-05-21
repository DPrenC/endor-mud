
#include "./path.h"

inherit SIM_ROOM;
create(){
    ::create();
    SetLocate("gorat");
    SetIntShort("la calle principal de Gorat");
    SetIntLong("Esta es la calle principal del peque�o y tranquilo pueblo pesquero de "
    "Gorat. La calle es larga y recta, la cual comienza en el puerto, que est� al "
    "oeste, y se adentra al interior hacia el este donde puedes encontrar, aparte de "
    "peque�as casas,  distintos locales como: el ayuntamiento, una taberna y el banco.\n");
    SetIntSmell("Desde aqu� ya se huele al puerto que est� al oeste.\n");
    SetIntNoise("Hacia el oeste se escucha el t�pico jaleo de todo puerto.\n");
    SetIndoors(0);
    AddExit("norte", "../casa_impreso/entrada");
    AddExit("oeste", CNS("puerto"));
    AddExit("este", "./callep1");
    AddDoor("norte", "la puerta de la casa del registro",
    "La puerta para entrar a la casa del registro.\n",
    ({"puerta", "puerta del sur", "puerta principal", "puerta de salida",
        "puerta de la calle"}));
    AddItem(GORPNJ("guard"), REFRESH_DESTRUCT, d2());
    AddItem(GORPNJ("ciudadan"), REFRESH_DESTRUCT, d2());
}
