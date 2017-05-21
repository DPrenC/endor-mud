/*
DESCRIPCION  : Dentro de ua casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab9_1.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creación.
[Maler]
--------------------------------------------------------------------------------
*/
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("berat");
    SetIntShort("la entrada de una casa");
    SetIntLong("Estás en lo que parece la entrada de la casa, parece bastante "
    "acogedora, Parece exótico, es posible que sea la casa de un marinero que "
    "ha viajado bastante por esos mundos.\n Al fondo están las escaleras "
    "que suben al segundo piso. Aparte de eso se puede ver un cuadro "
    "en la pared y un arcón cerrado junto a la escalera.\n");

    SetIntNoise("Lo único que escuchas es el distante rumor del mar.\n");
    SetIntSmell("Como cabe esperar, todo está impregnado con un olor a mar.\n");
    SetIntBright(30);

    AddDetail(({"cuadro","pintura"}),"El cuadro representa una bella mujer "
    "cabalgando sobre un precioso caballo.\n");

    AddDetail(({"arcon","arcón","cofre","caja"}),"El cofre está rematado en oro "
    "está hecho de las más ricas maderas que has visto jamás, está cerrado con llave.\n");

    AddDetail(({"escaleras","escaleras de madera"}),"Las escaleras que suben "
    "al segundo piso son bastante inclinadas, podrían ser peligrosas para alguien "
    "borracho.\n");

    AddExit("este","./ckol2");
    AddExit("arriba","./hab9_2");
    AddDoor("este", "la puerta de la calle");
}
