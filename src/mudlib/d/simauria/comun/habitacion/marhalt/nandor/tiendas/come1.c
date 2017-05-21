#include <mud.h>

#include "./path.h"

inherit SIM_ROOM;

create() {
::create();

SetIntShort("el comedor privado");
SetIntLong("El comedor es una pequenya habitacion ocupada totalmente por una mesa y dos "
           "grandes bancos todo hecho de madera, esta habitacion se usa como sala para "
           "comidas o reuniones privadas.\n");
SetIndoors(1);
SetIntBright(45);
SetIntNoise("El ruido de la sala pricipal es aqui menos fuerte.\n");
AddExit("sur","./posada");
}