/**
 * /torrewiz/rooms/mirill/workroom.c
 */

#include "path.h"
inherit ROOM;

create () {
    ::create();

    SetIntShort("la habitación de Mirill");
    SetIntLong(
"Esta es la habitación de Mirill.\n"
"Estas en los dominios privados de Mirill. Vas vale que el te haya invitado "
"porque si no toda su furia podria caer sobre ti. Aqui se aplica el viejo "
"dicho de: Se mira pero no se toca. Es una habitacion normal, como son todas "
"las habitaciones, con su cama, su armario, etc...\n"
"Ves una salida hacia la torre.\n"
          );
    SetIntBright(50);
    SetIndoors(1);

    AddExit("torre", TORRE("piso4/center"));
//  AddExit("nido", "/d/limbo/comun/habitacion/limbo/limbo/casasgods/mirill/nido1.c");
}

