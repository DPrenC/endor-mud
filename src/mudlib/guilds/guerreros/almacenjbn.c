/*
** Almac�n para Jugadores de Bajo Nivel
** Autor: Nemesis@Simauria, basado en el llpstorage de NF
*/

#include "wguild.h"
#include <rooms.h>
#include <properties.h>

inherit "/obj/guild/storage";

public void create() {
  ::create();
 SetIntShort("Almac�n para Guerreros de Bajo Nivel");
  SetIntLong(
    "Hay largas estanter�as de madera clavadas en las paredes,\n"
    "donde los guerreros pueden dejar su equipo para que otros\n"
    "lo usen si lo necesitan.\n"
    "El comando 'lista' te dira cu�ntas armas y armaduras se han\n"
    "dejado aqu� y cu�ntas han sido retiradas.\n"
    "Hay un cartel en la pared. �MIRALO!");
  SetIndoors(1);
  SetIntBright(40);

  AddDetail(({"estanterias","largas estanterias de madera",
	      "estanterias de madera","largas estanterias",
	      "estanter�as","largas estanter�as de madera",
	      "estanter�as de madera","largas estanter�as"}),
	    "Algunas veces est�n llenas de objetos �tiles\n"
	    "que puedes tomar prestados. Intenta volver a\n"
	    "traerlos para que otros los puedan usar tambi�n.\n");
  AddDetail(({"cartel"}),
            "ESTE ES UN SERVICIO QUE EL GREMIO DE GUERREROS OFRECE\n"
	    "GRATUITAMENTE A TODOS SUS MIEMBROS. ESTA PENSADO PARA\n"
	    "QUE OTROS JUGADORES PUEDAN BENEFICIARSE DE LOS OBJETOS\n"
	    "QUE YA NO NECESITAS. POR FAVOR, _DEJA_ OBJETOS ADEMAS\n"
	    "DE _COGER_. GRACIAS.\n"
	    "Nemesis, creador del Gremio de Guerreros.");

  SetGuild("guerrero");
  SetLevel(0);
  Set(P_CLEAN_UP,0);
  AddExit("este","./gguild");
  AddExit("oeste","./almacenjan");

 // AddItem("/obj/medpack",REFRESH_REMOVE,3);
}
