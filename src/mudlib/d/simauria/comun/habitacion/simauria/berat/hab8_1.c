/*
DESCRIPCION  : Dentro de ua casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab8_1.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creación.
[Maler]
--------------------------------------------------------------------------------
*/
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("Berat");
    SetIntShort("la planta baja de una casa");
    SetIntLong("Este es el primer piso de una casa normal y corriente. Posee un fogón pequeño "
    "pero funcional con el que poder preparar la comida. Por lo demás nada te llama la atención. "
    "Al lado están las escaleras al segundo piso.\n");

    SetIntNoise("Lo único que escuchas es el distante rumor del mar.\n");
    SetIntSmell("Como cabe esperar, todo está impregnado con un olor a mar.\n");
    SetIntBright(30);

    AddDetail(({"fogón", "fogon","cocina"}),"Parece que no ha sido usado durante mucho "
    "tiempo. Se ve los restos dejados por el último fuego.\n");

    AddDetail(({"escaleras","escaleras de madera"}),"Las escaleras que suben "
    "al segundo piso son bastante inclinadas, podrían ser peligrosas para alguien "
    "borracho.\n");

    AddExit("este","./ckol1");
    AddExit("arriba","./hab8_2");
    AddDoor("este", "la puerta de la calle");
}
