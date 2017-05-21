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
  Set(P_INT_SHORT, "La habitaci�n de " NAME "\n");
  Set(P_INT_LONG,
 "Esta es la habitaci�n de " NAME ".\n"
"Desde que " NAME " fue hecho wizard, est� completamente vac�a, pero\n"
"no deja de ser muy confortable.\n"
          );
  AddExit("torre", TORRE);
}

