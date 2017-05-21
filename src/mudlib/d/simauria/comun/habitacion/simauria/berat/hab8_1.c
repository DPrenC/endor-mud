/*
DESCRIPCION  : Dentro de ua casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab8_1.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creaci�n.
[Maler]
--------------------------------------------------------------------------------
*/
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("Berat");
    SetIntShort("la planta baja de una casa");
    SetIntLong("Este es el primer piso de una casa normal y corriente. Posee un fog�n peque�o "
    "pero funcional con el que poder preparar la comida. Por lo dem�s nada te llama la atenci�n. "
    "Al lado est�n las escaleras al segundo piso.\n");

    SetIntNoise("Lo �nico que escuchas es el distante rumor del mar.\n");
    SetIntSmell("Como cabe esperar, todo est� impregnado con un olor a mar.\n");
    SetIntBright(30);

    AddDetail(({"fog�n", "fogon","cocina"}),"Parece que no ha sido usado durante mucho "
    "tiempo. Se ve los restos dejados por el �ltimo fuego.\n");

    AddDetail(({"escaleras","escaleras de madera"}),"Las escaleras que suben "
    "al segundo piso son bastante inclinadas, podr�an ser peligrosas para alguien "
    "borracho.\n");

    AddExit("este","./ckol1");
    AddExit("arriba","./hab8_2");
    AddDoor("este", "la puerta de la calle");
}
