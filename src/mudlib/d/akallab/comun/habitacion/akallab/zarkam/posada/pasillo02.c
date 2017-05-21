/*
DESCRIPCION : pasillo de la posada
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/posada/pasillo02.c
MODIFICACION: 15-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "./path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el pasillo de la posada");
  SetIntLong(
    "Te hallas en medio del pasillo que recorre esta planta de la posada y que "
    "permite llegar a las distintas habitaciones. Oyes a alguien roncar.\n");

  SetIntNoise("Se oye a alguien roncar.\n");
  SetIntSmell("Hmm.. quiza alguien deberia abrir una ventana para ventilar el pasillo.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(1);
  SetIntBright(50);

  AddExit("norte",Z_POSADA("habitacion02"));
  AddExit("sur",Z_POSADA("habitacion05"));
  AddExit("este",Z_POSADA("pasillo01"));
  AddExit("oeste",Z_POSADA("pasillo03"));
}
