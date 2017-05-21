
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("un dormitorio");
    SetIntLong(
    "La estancia es un gran dormitorio con una gran cama que se halla "
    "en ella, tanto las cortinas como la tapicería de cada uno de los muebles están "
    "hechas por verdaderos artesanos, a juzgar por su perfecto acabado.\n");
    SetIntSmell("La habitación está perfumada con deliciosos aromas.\n");
    SetIntBright(35);
    AddDetail("muebles",
    "Están bien fabricados y parecen sólidos.\n");
    AddDetail("cortinas",
    "Quien las eligió tenía buen gusto.\n");
    AddExit("este", "./pasillo2");
    AddDoor("este", "una puerta de madera",
    "Una puerta de madera para volver al pasillo.\n",
    ({"puerta", "puerta de madera", "puerta del pasillo", "puerta del este"}));
    SetLocate("el castillo de Nandor");
}
