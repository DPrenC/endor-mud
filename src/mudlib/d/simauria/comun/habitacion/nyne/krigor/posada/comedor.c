
#include "path.h"

inherit SIM_ROOM;

create() {
    ::create();

    SetIntShort("un comedor privado");
    SetIntLong("Este comedor es una pequeña habitacion ocupada totalmente por una "
    "mesa y dos grandes bancos, todo hecho de madera. Se usa como sala para comidas "
    "o reuniones privadas.\n");
    SetIntBright(45);
    SetIntNoise("El ruido de la sala pricipal es aquí menos fuerte.\n");
    AddExit("oeste",KRIGOR("posada/posada"));
}
