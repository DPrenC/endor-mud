// 03-03-03 Modificación: Cambio hermita por ermita. [z]


#include "./path.h"

inherit SIM_ROOM;
create () {
    ::create();
    SetLocate("puerto de Gorat");
    SetIntShort("la ermita de la Diosa Valevissa");
    SetIntLong(
    "Estás en la puerta de la ermita de la Diosa Humana del mar Valevissa, "
    "es un lugar de culto donde los pescadores rinden homenaje a su Diosa y "
    "y le piden que les favorezca la pesca a principio de temporada.\n "
    "Es una ermita pequeña, en la que puedes ver una imagen de la Diosa.\n "
    "Al norte está el altar de la ermita.\n");
    SetIntBright(30);
    AddDetail("imagen",
    "Es la imagen de la Diosa del mar Valevissa, es una imagen humana femenina "
    "de cabellos rubios y ojos azul mar, andando sobre las aguas.\n");
    SetIntNoise("Escuchas el rumor del mar fuera de la ermita.\n");
    SetIntSmell("Aquí dentro también huele a mar.\n");
    AddExit("sur","../playa/playa5");
    AddExit("norte","./altar");
    AddDoor("sur", "la puerta de salida",
    "Es una puerta de madera corroída por el salitre del mar, da salida a la playa.\n",
    ({"puerta", "puerta de salida", "puerta del sur", "puerta de madera"}));
    switch(d2()){
        case 1:
            AddItem(GORPNJ("ciudadan"), REFRESH_DESTRUCT); break;
        case 2:
            AddItem(GORPNJ("mujer"), REFRESH_DESTRUCT); break;
    }

}
