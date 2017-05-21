/*
DESCRIPCION  : Primer piso de una casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab1_1.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creación.
[Mal]
--------------------------------------------------------------------------------
*/
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("berat");
    SetIntShort("la planta baja de una casa");
    SetIntLong("Estás en la planta baja de la casa, es la típica casa "
    "acogedora para los humanos, todo a tu alrededor es de origen exótico.\n "
    "Supuestamente es la casa de un marino que ha viajado  bastante por esos mundos.\n "
    " Al fondo están unas escaleras que suben al segundo piso, un bonito cuadro "
    "adorna la pared y un arcón cerrado espera pacientemente junto a la escalera.\n");

    SetIntNoise("Lo único que escuchas es el distante rumor del mar.\n");
    SetIntSmell("Como cabe de esperar, todo está impregnado con un olor a mar.\n");
    SetIntBright(30);

    AddDetail(({"cuadro","pintura"}),"El cuadro representa una batalla "
    "entre dos flotas de barcos.\n");

    AddDetail(({"arcón","cofre","caja"}),"El cofre parece antiguo por "
    "el color de la madera con el que está hecho, está cerrado con llave.\n");

    AddDetail(({"escaleras","escaleras de madera"}),"Las escaleras que suben "
    "al segundo piso son bastante inclinadas,podrían ser peligrosas para alguien "
    "borracho.\n");

    AddExit("este","./cprin2");
    AddExit("arriba","./hab1_2");
    AddDoor("este", "la puerta de la calle");
}
