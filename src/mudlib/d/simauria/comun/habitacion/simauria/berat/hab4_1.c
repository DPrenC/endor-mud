/*
DESCRIPCION  : Dentro de ua casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab4_1.c
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
    SetIntLong("Estás en lo que parece la entrada de la casa, parece bastante "
    "vieja, pero perfectamente adaptable.\n Hay unas escaleras  que suben al segundo "
    "piso, aparte de eso puedes ver un gran sillón de cuero "
    "apoyado en la pared.\n");

    SetIntNoise("Lo único que escuchas es el distante rumor del mar.\n");
    SetIntSmell("Como cabe esperar, todo está impregnado con un olor a mar.\n");
    SetIntBright(30);

    AddDetail(({"sillón","sillon","butaca"}),"El sillón está hecho de cuero negro y parece "
    "muy cómodo, lástima que no tengas tiempo para sentarte en él.\n");

    AddDetail(({"escaleras","escaleras de madera"}),"Las escaleras que suben "
    "al segundo piso son bastante inclinadas, podrían ser peligrosas para alguien "
    "borracho.\n");

    AddExit("este","./cmerc1");
    AddExit("arriba","./hab4_2");
    AddDoor("este", "la puerta de la calle");
}
