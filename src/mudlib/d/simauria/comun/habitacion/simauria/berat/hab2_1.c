/*
DESCRIPCION  : Entrada de una casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab2_1.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creaci�n.
[Maler]
-------------------------------------------------------------------------------
*/
#include "./path.h"


inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("berat");
    SetIntShort("el vestibulo de una casa");
    SetIntLong("Est�s en el vest�bulo de una casa de aspecto bastante sobrio "
    "pero acogedor, todo est� cubierto por tapices de distintos dise�os y color. "
    "En el suelo se extiende una alfombra. Al fondo se ven unas escaleras "
    "que suben a lo que parece ser el segundo piso.\n");

    SetIntNoise("Lo �nico que escuchas es el distante rumor del mar.\n");
    SetIntSmell("Como cabe esperar, todo est� impregnado con un olor a mar.\n");
    SetIntBright(30);

    AddDetail(({"tapices","tapiz"}),"Los tapices que recubren las paredes parecen  "
    "caros y cumplen su funci�n decorativa a las mil maravillas.\n");

    AddDetail(({"alfombra","celpudo"}),"La alfombra es de una exquisita manufactura "
    "tiene unos extra�os dibujos y figuras geom�tricas por toda su superficie.\n");

    AddDetail(({"escaleras","escaleras de madera"}),"Las escaleras que suben "
    "al segundo piso son bastante inclinadas, podr�an ser peligrosas para alguien "
    "borracho.\n");

    AddExit("este","./cprin3");
    AddExit("arriba","./hab2_2");
    AddDoor("este", "la puerta de la calle");
}
