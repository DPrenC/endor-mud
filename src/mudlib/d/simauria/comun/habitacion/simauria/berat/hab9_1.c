/*
DESCRIPCION  : Dentro de ua casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab9_1.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creaci�n.
[Maler]
--------------------------------------------------------------------------------
*/
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("berat");
    SetIntShort("la entrada de una casa");
    SetIntLong("Est�s en lo que parece la entrada de la casa, parece bastante "
    "acogedora, Parece ex�tico, es posible que sea la casa de un marinero que "
    "ha viajado bastante por esos mundos.\n Al fondo est�n las escaleras "
    "que suben al segundo piso. Aparte de eso se puede ver un cuadro "
    "en la pared y un arc�n cerrado junto a la escalera.\n");

    SetIntNoise("Lo �nico que escuchas es el distante rumor del mar.\n");
    SetIntSmell("Como cabe esperar, todo est� impregnado con un olor a mar.\n");
    SetIntBright(30);

    AddDetail(({"cuadro","pintura"}),"El cuadro representa una bella mujer "
    "cabalgando sobre un precioso caballo.\n");

    AddDetail(({"arcon","arc�n","cofre","caja"}),"El cofre est� rematado en oro "
    "est� hecho de las m�s ricas maderas que has visto jam�s, est� cerrado con llave.\n");

    AddDetail(({"escaleras","escaleras de madera"}),"Las escaleras que suben "
    "al segundo piso son bastante inclinadas, podr�an ser peligrosas para alguien "
    "borracho.\n");

    AddExit("este","./ckol2");
    AddExit("arriba","./hab9_2");
    AddDoor("este", "la puerta de la calle");
}
