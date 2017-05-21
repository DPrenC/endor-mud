/*
** Almac�n para JANs
** Autor: Nemesis@Simauria, basado en el hlpstorage de NF
**
*/

#include <rooms.h>
#include "../../wguild.h"

inherit "/obj/guild/storage";

public void create()
{
  ::create();
  SetIntShort("el almac�n para Guerreros de Alto Nivel");
  SetIntLong(
    "Hay largas estanter�as de madera donde los guerreros de alto nivel\n"
    "pueden dejar objetos para que otros puedan cogerlos si los necesitan.\n"
    "El comando 'lista' te dir� cu�ntas armas y armaduras han sido dejadas\n"
    "aqu� y cu�ntas han sido retiradas.\n");
  SetIndoors(1);
  SetIntBright(20);

  SetGuild("guerrero");
  SetLevel(30);
  AddDetail(({"estanterias","largas estanterias de madera",
	      "estanterias de madera","largas estanterias",
	      "estanter�as","largas estanter�as de madera",
	      "estanter�as de madera","largas estanter�as"}),
	    "A veces est�n llenas de cosas �tiles que puedes\n"
	    "tomar prestadas. Pero aseg�rate de volver a\n"
	    "traerlas, para que otros puedan usarlas.\n");
  AddItem("/guilds/guerreros/jan_obj/hacha");
  AddExit("este","./almacenjbn");

}

