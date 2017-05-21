/*
DESCRIPCION  : Dentro de ua casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab4_1.c
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
    SetIntLong("Est�s en lo que parece la entrada de la casa, parece bastante "
    "vieja, pero perfectamente adaptable.\n Hay unas escaleras  que suben al segundo "
    "piso, aparte de eso puedes ver un gran sill�n de cuero "
    "apoyado en la pared.\n");

    SetIntNoise("Lo �nico que escuchas es el distante rumor del mar.\n");
    SetIntSmell("Como cabe esperar, todo est� impregnado con un olor a mar.\n");
    SetIntBright(30);

    AddDetail(({"sill�n","sillon","butaca"}),"El sill�n est� hecho de cuero negro y parece "
    "muy c�modo, l�stima que no tengas tiempo para sentarte en �l.\n");

    AddDetail(({"escaleras","escaleras de madera"}),"Las escaleras que suben "
    "al segundo piso son bastante inclinadas, podr�an ser peligrosas para alguien "
    "borracho.\n");

    AddExit("este","./cmerc1");
    AddExit("arriba","./hab4_2");
    AddDoor("este", "la puerta de la calle");
}
