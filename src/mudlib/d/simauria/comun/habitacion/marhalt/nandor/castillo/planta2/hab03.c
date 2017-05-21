
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("un dormitorio doble");
    SetIntLong(
    "El dormitorio está bien cuidado y las dos camas que hay están perfectamente "
    "hechas. Ves una mesita de noche con sus candelabros a cada lado de las camas.\n "
    "En la pared norte está la puerta del pasillo.\n");
    SetIntBright(35);
    AddDetail(({"mesita","mesitas"}),
    "Unas mesitas de noche de caoba con adornos dorados.\n");
    AddDetail("candelabros",
    "Unos candelabros de bronce para iluminar la estancia por la noche.\n");
    AddDetail("camas",
    "Están perfectamente hechas. No hay ni una arruga. Sin duda los sirvientes hacen "
    "muy bien su trabajo.\n");
    AddExit("norte", "./pasillo3");
    AddDoor("norte", "una puerta de madera",
    "Una puerta de madera para volver al pasillo.\n",
    ({"puerta", "puerta de madera", "puerta del pasillo", "puerta del norte"}));
    SetLocate("el castillo de Nandor");
}
