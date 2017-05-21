#include "./path.h"
inherit KHA_ROOM;

create()
{
    ::create();
    SetIntShort("el pasillo de las celdas");
    SetIntLong("En medio del pasillo, donde deber�a haber una puerta, no la hay.\nComparado "
        "con el resto del corredor esta parte parece desierta.\n");
    SetIndoors(1);
    SetIntBright(10);
    SetIntNoise("No oyes nada, lo que se dice nada.\n");
    SetIntSmell("Aqu� huele un poco mas fuerte a humedad.\n");
    AddDetail(({"muro"}),"Te fijas y en el muro puedes ver los trazos de un dibujo que ocupa "
        "toda la secci�n.\n");
    AddDetail(({"trazos","dibujo"}),"Los trazos forman un s�mbolo, un martillo alado dentro de "
        "un rombo.\nEl grabado es perfecto. Las l�neas permanecen intactas como el primer d�a.\n");
    AddExit("este",("14pas"));
    AddExit("oeste",("12pas"));
    SetLocate("las mazmorras");
}
