/*
DESCRIPCION  : Dentro de ua casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab5_1.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creación.
[Maler]
--------------------------------------------------------------------------------
*/
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("berat");
    SetIntShort("la planta baja de una casa");
    SetIntLong("Estás en la planta baja de una casa bastante grande, apenas está decorado "
    "por lo que deduces que sus dueños estan todavía mudándose. Puedes ver cajas por todos lados "
    "quizás si mirases podrías encontrar algo de tu interés...\n");

    SetIntNoise("Lo único que escuchas es el distante rumor del mar.\n");
    SetIntSmell("Como cabe esperar, todo está impregnado con un olor a mar.\n");
    SetIntBright(30);

    AddDetail(({"caja","cajas"}),"Por todas partes ves cajas de madera cerradas con clavos "
    "parece que los dueños aprecian de verdad lo que llevan ahí dentro.\n");

    AddDetail(({"escaleras","escaleras de madera"}),"Las escaleras que suben "
    "al segundo piso son bastante inclinadas, podrían ser peligrosas para alguien "
    "borracho.\n");

    AddExit("este","./cmerc3");
    AddExit("arriba","./hab5_2");
    AddDoor("este", "la puerta de la calle");
}