/*
DESCRIPCION : pasillo de la posada
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/posada/pasillo00.c
MODIFICACION: 15-10-98 [Angor@Simauria] Creacion
		30-10-98 [Chaos] comentada la salida a la habitacion00
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el pasillo de la posada");
  SetIntLong(
     "Te encuentras en un pasillo de la planta baja de la posada junto a las escaleras "
     "que permiten subir a las plantas superiores. Al sur de aqui se halla la "
     "habitacion de la posada en la que viven sus propietarios. La puerta que hay al "
     "norte conduce a los establos donde los huespedes dejan a sus monturas mientras "
     "estan alojados en la posada. Hacia el oeste, el pasillo llega hasta llega a una "
     "amplia estancia donde se halla en comedor.\n");

  AddDetail(({"establos","establo"}),"La puerta que queda al norte conduce a ellos.\n");
  AddDetail(({"sala","comedor"}),"Esta al oeste de aqui.\n");
  AddDetail(({"escaleras","escalera"}),
     "Es una ancha escalera de madera que comunica las distintas plantas de la posada.\n");

  SetIntNoise("Se oye el a la gente del comedor.\n");
  SetIntSmell("Hmm.. huele a comida.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(1);
  SetIntBright(50);

  AddExit("norte",Z_POSADA("establo"));
//  AddExit("sur",Z_POSADA("habitacion00"));
  AddExit("oeste",Z_POSADA("comedor02"));
  AddExit("arriba",Z_POSADA("pasillo01"));
}
