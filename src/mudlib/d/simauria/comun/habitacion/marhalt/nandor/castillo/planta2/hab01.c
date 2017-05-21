
#include <properties.h>
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("un dormitorio");
    SetIntLong(
    "La estancia es un gran dormitorio con una gran cama que se halla "
    "en ella, tanto las cortinas como la tapicer�a de cada uno de los muebles est�n "
    "hechas por verdaderos artesanos, a juzgar por su perfecto acabado.\n");
    SetIntSmell("La habitaci�n est� perfumada con deliciosos aromas.\n");
    SetIntBright(35);
    AddDetail("muebles",
    "Est�n bien fabricados y parecen s�lidos.\n");
    AddDetail("cortinas",
    "Quien las eligi� ten�a buen gusto.\n");
    AddExit("este", "./pasillo2");
    AddDoor("este", "una puerta de madera",
    "Una puerta de madera para volver al pasillo.\n",
    ({"puerta", "puerta de madera", "puerta del pasillo", "puerta del este"}));
    SetLocate("el castillo de Nandor");
}
