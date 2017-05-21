/*
DESCRIPCION : pasillo de la posada
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/posada/pasillo01.c
MODIFICACION: 15-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el pasillo de la posada");
  SetIntLong(
    "Te encuentras al principio del pasillo que recorre esta planta de la posada y "
    "que permite llegar a las distintas habitaciones. Una escalera permite bajar "
    "a la planta baja y subir al desvan. Oyes a alguien roncar.\n");

  AddDetail(({"escalera"}),
    "Es una ancha escalera de madera que comunica las distintas plantas de la posada.\n");

  SetIntNoise("Se oye a alguien roncar.\n");
  SetIntSmell("Hmm.. quiza alguien deberia abrir una ventana para ventilar el pasillo.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(1);
  SetIntBright(50);

  AddExit("norte",Z_POSADA("habitacion03"));
  AddExit("sur",Z_POSADA("habitacion06"));
  AddExit("oeste",Z_POSADA("pasillo02"));
  AddExit("arriba",Z_POSADA("desvan01"));
  AddExit("abajo",Z_POSADA("pasillo00"));
}
