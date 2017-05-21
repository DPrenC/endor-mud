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
    "hay unos enormes amarres. Desde aqu�, puedes contemplar el agua del mar y a lo lejos "
    "puedes ver la bah�a y el delta del Racksal.\n En este lugar hace escala la "
    "radiante, una de las embarcaciones que tienen servicio para pasajeros.\n Puedes "
    "leer la tabla de informaci�n de los barcos.\n");
    SetClimateServer(SERVER);

    SetIntNoise("Oyes las olas chocar contra el muelle.\n");
    SetIntSmell("Huele a agua salada.\n");
    SetLocate("Berat");
    SetIndoors(0);
    AddDetail(({"agua", "el mar","mar"}),"Te sientes empeque�ecido ante la inmensidad "
    "del oc�ano.\n");
    AddDetail(({"bah�a","Bahia","bahia","Bah�a"}),"Es la Bah�a de Mizar, en medio ves "
    "un enorme delta.\n");
    AddDetail(({"Delta","delta"}),"Es el delta del r�o Racksal.\n");
    AddDetail(({"Racksal","racksal","r�o","r�o"}),"Es un enorme r�o navegable.\n");
    AddDetail(({"muelle","el muelle"}),"El muelle esta hecho de madera, parece "
    "bastante viejo pero s�lido.\n");
    AddShip(RADIANTE("radiante"));
    AddExit("este","./muelle02");
    AddItem(PNJ("simauria/berat/manga"),REFRESH_DESTRUCT);

}
