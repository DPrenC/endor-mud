/*
DESCRIPCION  : Dentro de ua casa
FICHERO      : /d/simauria/comun/habitacion/simauria/berat/hab6_1.c
MODIFICACION : 05-11-99 [Jorus@Simauria] Creaci�n.
[Maler]
--------------------------------------------------------------------------------
*/
#include "./path.h"

inherit SIM_ROOM;

create() {
    ::create();
    SetLocate("berat");
    SetIntShort("el vest�bulo de una casa");
    SetIntLong("Est�s en el vest�bulo de una casa de aspecto bastante sobrio "
    "todo est� cubierto por una capa de polvo, que indica que ha estado desahabitada "
    "durante largo tiempo.\n  Puedes ver, impresas en el suelo, rastros de pisadas recientes, "
    "seguramente de los nuevos inquilinos de la casa.\n");

    SetIntNoise("Lo �nico que escuchas es el distante rumor del mar.\n");
    SetIntSmell("Como cabe esperar, todo est� impregnado con un olor a mar.\n");
    SetIntBright(30);

    AddDetail("pisadas","Las pisadas son numerosas y recientes, lo que parece indicar  "
    "que los nuevos due�os se piensan trasladar dentro de poco.\n");

    AddExit("oeste","./cmerc2");
    AddDoor("oeste", "la puerta de la calle");
}