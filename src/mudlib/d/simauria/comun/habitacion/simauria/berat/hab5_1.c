/*
DESCRIPCION  : Dentro de ua casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab5_1.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creaci�n.
[Maler]
--------------------------------------------------------------------------------
*/
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("berat");
    SetIntShort("la planta baja de una casa");
    SetIntLong("Est�s en la planta baja de una casa bastante grande, apenas est� decorado "
    "por lo que deduces que sus due�os estan todav�a mud�ndose. Puedes ver cajas por todos lados "
    "quiz�s si mirases podr�as encontrar algo de tu inter�s...\n");

    SetIntNoise("Lo �nico que escuchas es el distante rumor del mar.\n");
    SetIntSmell("Como cabe esperar, todo est� impregnado con un olor a mar.\n");
    SetIntBright(30);

    AddDetail(({"caja","cajas"}),"Por todas partes ves cajas de madera cerradas con clavos "
    "parece que los due�os aprecian de verdad lo que llevan ah� dentro.\n");

    AddDetail(({"escaleras","escaleras de madera"}),"Las escaleras que suben "
    "al segundo piso son bastante inclinadas, podr�an ser peligrosas para alguien "
    "borracho.\n");

    AddExit("este","./cmerc3");
    AddExit("arriba","./hab5_2");
    AddDoor("este", "la puerta de la calle");
}