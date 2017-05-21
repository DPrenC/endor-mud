/*
DESCRIPCION  :  Extremo del muelle del puerto
FICHERO      :  /d/simauria/comun/habitacion/simauria/berat/muelle01.c
*/

#include "./path.h"
inherit PORT;

create() {
    ::create();
    SetIntShort("un extremo del muelle del puerto");
    SetIntLong("Te encuentras en el extremo occidental del muelle. En el borde "
    "hay unos enormes amarres. Desde aquí, puedes contemplar el agua del mar y a lo lejos "
    "puedes ver la bahía y el delta del Racksal.\n En este lugar hace escala la "
    "radiante, una de las embarcaciones que tienen servicio para pasajeros.\n Puedes "
    "leer la tabla de información de los barcos.\n");
    SetClimateServer(SERVER);

    SetIntNoise("Oyes las olas chocar contra el muelle.\n");
    SetIntSmell("Huele a agua salada.\n");
    SetLocate("Berat");
    SetIndoors(0);
    AddDetail(({"agua", "el mar","mar"}),"Te sientes empequeñecido ante la inmensidad "
    "del océano.\n");
    AddDetail(({"bahía","Bahia","bahia","Bahía"}),"Es la Bahía de Mizar, en medio ves "
    "un enorme delta.\n");
    AddDetail(({"Delta","delta"}),"Es el delta del río Racksal.\n");
    AddDetail(({"Racksal","racksal","río","río"}),"Es un enorme río navegable.\n");
    AddDetail(({"muelle","el muelle"}),"El muelle esta hecho de madera, parece "
    "bastante viejo pero sólido.\n");
    AddShip(RADIANTE("radiante"));
    AddExit("este","./muelle02");
    AddItem(PNJ("simauria/berat/manga"),REFRESH_DESTRUCT);

}
