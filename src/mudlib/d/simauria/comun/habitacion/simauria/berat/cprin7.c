/*
DESCRIPCION  : calle principal
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/cprin7.c

--------------------------------------------------------------------------------
*/
#include "./path.h"
inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("Berat");
    SetIntShort("la calle principal");
    SetIntLong("Estás en la calle principal.\n En este punto se une al oeste con la "
    "calle de la sirena, o calle de las tabernas.\n La calle continúa al norte "
    "mientras que al sur se acerca al puerto y el cuartel de la guardia. Al este se "
    "encuentra la puerta de entrada al templo.\n");
    SetIndoors(0);
    SetIntNoise("Escuchas el bullicio típico de los pueblos comerciantes.\n");
    AddDetail(({"cuartel", "cuartel de la guardia"}),
    "Es un edificio de 2 plantas que se encuentra algo más al sur.\n");
    AddDetail("puerto", "Ya se puede ver a lo lejos hacia el sur.\n");
    AddDetail(({"camino","calle"}),"Es la calle mas grande de Berat "
    " y las piedras que lo forman estan muy desgastadas.\n");
    AddDetail("piedras","Parecen cantos rodados, muy desgastados.\n");
    AddExit("norte","./cprin6");
    AddExit("oeste","./ctab1");
    AddExit ("sur","./cprin8");
    AddExit("este","./ermita");
    AddDoor("este", "la puerta del templo",
    "Es una puerta de madera maciza para entrar al templo de Berat.\n",
    ({"puerta", "puerta del templo", "puerta del este", "puerta de madera maciza"}));
    AddItem(PNJ("simauria/berat/ciuda1"), REFRESH_DESTRUCT, d2());
}

