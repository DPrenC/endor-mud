/*
DESCRIPCION  : De momento tan solo es un local vac�o, antes era el acceso al puerto.
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/cpuerto.c

--------------------------------------------------------------------------------
*/
#include "./path.h"
inherit SIM_ROOM;
create() {
    ::create();
    SetLocate("Berat");
    SetIntShort("un solar abandonado");
    SetIntLong("Se trata de un solar abandonado lleno de maleza por todas partes. "
    "Teniendo en cuenta tanta vegetaci�n es provable que esto lleve as� demasiados "
    "a�os.\n Al este se ve el viejo cuartel de la guardia, al sur el muelle del "
    "puerto y al norte est� la calle de las tabernas.\n");
    SetIndoors(0);
    SetIntNoise("Escuchas el ruido de las olas chocando contra el muelle.\n");
    AddDetail(({"cuartel", "viejo cuarttel"}), "Es un edificio de madera vieja de "
    "dos plantas.\n");
    AddDetail(({"muelle", "puerto"}), "Est� al sur y se ve a gente trabajando, as� "
    "como unos cuantos barcos amarrados.\n");
    AddDetail(({"barcos", "barco"}), "Son varios, est�n amarrados en el muelle.\n");
    AddExit("norte","./ctab1");
    AddExit("sur","./muelle06");
    AddExit("este", "./cprin8");
}

