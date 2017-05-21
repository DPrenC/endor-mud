/*
** Almac�n para Jugadores de Bajo Nivel
** Autor: Nemesis@Simauria, basado en el llpstorage de NF
*/

#include "../../wguild.h"
#include <rooms.h>
#include <properties.h>

inherit "/obj/guild/storage";

public void create()
{
  ::create();
  SetIntShort("el almac�n para Guerreros de Bajo Nivel");
  SetIntLong(
    "Hay largas estanter�as de madera clavadas en las paredes,\n"
    "donde los guerreros pueden dejar su equipo para que otros\n"
    "lo usen si lo necesitan.\n"
    "El comando 'lista' te dira cu�ntas armas y armaduras se han\n"
    "dejado aqu� y cu�ntas han sido retiradas.\n");
  SetIndoors(1);
  SetIntBright(20);

  AddDetail(({"estanterias","largas estanterias de madera",
	      "estanterias de madera","largas estanterias",
	      "estanter�as","largas estanter�as de madera",
	      "estanter�as de madera","largas estanter�as"}),
	    "Algunas veces est�n llenas de objetos �tiles\n"
	    "que puedes tomar prestados. Intenta volver a\n"
	    "traerlos para que otros los puedan usar tambi�n.\n");
  SetGuild("guerrero");
  SetLevel(0);
  Set(P_CLEAN_UP,0);
  AddExit("este","./sede_kha-annu");
  AddExit("oeste","./almacenjan");

 // AddItem("/obj/medpack",REFRESH_REMOVE,8);
}
