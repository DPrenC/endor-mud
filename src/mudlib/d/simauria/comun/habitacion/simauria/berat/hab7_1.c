/*
DESCRIPCION  : Dentro de ua casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab7_1.c
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
    SetIntLong("Est�s en la entrada de una casa bastante grande, es algo vieja, "
    "pero todav�a le queda vida.\n Para los humanos resultar�a acogedora. Posiblemente"
    " es la casa de un marinero que ha viajado  bastante.\n Al fondo puedes ver "
    "unas escaleras que suben al segundo piso, y en el suelo se aprecia una trampilla "
    "en el suelo.\n");

    SetIntNoise("Lo �nico que escuchas es el distante rumor del mar.\n");
    SetIntSmell("Como cabe esperar, todo est� impregnado con un olor a mar.\n");
    SetIntBright(30);

    AddDetail("trampilla","La trampilla est� abierta, dando la posibilidad de bajar "
    "al s�tano.\n");

    AddDetail(({"escaleras","escaleras de madera"}),"Las escaleras que suben "
    "al segundo piso son bastante inclinadas, podr�an ser peligrosas para alguien "
    "borracho.\n");

    AddExit("norte","./ctab3");
    AddExit("arriba","./hab7_2");
    AddExit("abajo","./hab7_0");
    AddDoor("norte", "la puerta de la calle");
}
