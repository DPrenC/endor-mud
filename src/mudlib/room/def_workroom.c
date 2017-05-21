/* La habitacion por defecto de los nuevos wizards. Se copia a su home*/

#ifndef NAME
#define NAME "Alguien"
#endif
#define TORRE "/d/limbo/comun/habitacion/limbo/torrewiz/sotano/center"

#include <stdrooms.h>
#include <properties.h>

inherit ROOM;

create () {
  ::create();
  Set(P_INT_SHORT, "La habitación de " NAME "\n");
  Set(P_INT_LONG,
 "Esta es la habitación de " NAME ".\n"
"Desde que " NAME " fue hecho wizard, está completamente vacía, pero\n"
"no deja de ser muy confortable.\n"
          );
  AddExit("torre", TORRE);
}

