#include "./path.h"
inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("el pasillo de las celdas");
    SetIntLong("En medio del pasillo, donde debería haber una puerta, no la hay.\nComparado "
        "con el resto del corredor esta parte parece desierta.\n");
    SetIndoors(1);
    SetIntBright(10);
    SetIntNoise("No oyes nada, lo que se dice nada.\n");
    SetIntSmell("Aquí huele un poco mas fuerte a humedad.\n");
    AddDetail(({"muro"}),"Te fijas y en el muro puedes ver los trazos de un dibujo que ocupa "
        "toda la sección.\n");
    AddDetail(({"trazos","dibujo"}),"Los trazos forman un símbolo, un martillo alado dentro de "
        "un rombo.\nEl grabado es perfecto. Las líneas permanecen intactas como el primer día.\n");
    AddExit("este",("14pas"));
    AddExit("oeste",("12pas"));
    SetLocate("las mazmorras");
}
