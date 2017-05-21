/*
** Almacén para JANs
** Autor: Nemesis@Simauria, basado en el hlpstorage de NF
*/
#include <rooms.h>
#include "./wguild.h"

inherit "/obj/guild/storage";

public void create() {
  ::create();
 SetIntShort("Almacén para Guerreros de Alto Nivel");
  SetIntLong(
    "Hay largas estanterías de madera donde los guerreros de alto nivel\n"
    "pueden dejar objetos para que otros puedan cogerlos si los necesitan.\n"
    "El comando 'lista' te dirá cuántas armas y armaduras han sido dejadas\n"
    "aquí y cuántas han sido retiradas.\n"
    "Hay un cartel en la pared. ¡MIRALO!\n");
  SetIndoors(1);
  SetIntBright(45);

  SetGuild("guerrero");
  SetLevel(30);
  AddDetail(({"estanterias","largas estanterias de madera",
	      "estanterias de madera","largas estanterias",
	      "estanterías","largas estanterías de madera",
	      "estanterías de madera","largas estanterías"}),
	    "A veces están llenas de cosas útiles que puedes\n"
	    "tomar prestadas. Pero asegúrate de volver a\n"
	    "traerlas, para que otros puedan usarlas.\n");
  AddDetail(({"cartel"}),
            "ESTE ES UN SERVICIO QUE EL GREMIO DE GUERREROS OFRECE\n"
	    "GRATUITAMENTE A TODOS SUS MIEMBROS. ESTA PENSADO PARA\n"
	    "QUE OTROS JUGADORES PUEDAN BENEFICIARSE DE LOS OBJETOS\n"
	    "QUE YA NO NECESITAS. POR FAVOR, _DEJA_ OBJETOS ADEMAS\n"
	    "DE _COGER_. GRACIAS.\n"
	    "Nemesis, creador del Gremio de Guerreros.");

  AddItem(JAN_OBJ+"katana");
  AddExit("este","./almacenjbn");

}

