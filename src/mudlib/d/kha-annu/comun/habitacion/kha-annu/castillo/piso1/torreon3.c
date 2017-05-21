#include "path.h"

inherit KHA_ROOM;
create() {
   ::create();
SetIntShort("el último piso del Torreón Central");
SetIntLong(
"Te encuentras en el ultimo piso del torreon del Castillo Kha-annu. Desde aqui "
"alcanzas a ver las tierras que rodean este palacio situado en medio de las "
"montanyas. El patio esta justo debajo de aqui.\n");

SetIntBright(70);

SetIndoors(1);

AddExit("abajo", PISO1+"torreon2");

AddDetail(({"tierra","tierras"}),
"Ves parte de las inmensas tierras gelidas del norte conocidas como Tierras "
"Altas.\n");
AddDetail("patio",
"El patio del castillo con sus columnas y arcos esta ahora bajo tus pies.\n");
AddDetail(({"pared","paredes"}),
"Las paredes son antiguas, pero muy solidas y resistentes.\n");
AddDetail(({"escalera","escaleras"}),
"Unas frias escaleras de caracol conducen a la parte baja del torreon.\n");
/*
AddItem(MAGIA+"esp_silb",REFRESH_DESTRUCT,1);
*/
}