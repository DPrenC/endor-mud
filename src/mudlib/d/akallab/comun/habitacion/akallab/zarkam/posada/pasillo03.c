/*
DESCRIPCION : pasillo de la posada
FICHERO     : /d/akallab/comun/habitacion/akallab/zarkam/posada/pasillo03.c
MODIFICACION: 15-10-98 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
inherit ROOM;

create() {
  ::create();
  SetIntShort("el pasillo de la posada");
  SetIntLong(
    "Te encuentras al final del pasillo que recorre esta planta de la posada y que "
    "permite llegar a las distintas habitaciones. No hay nada destacable en el salvo "
    "que quiza haria falta darle alguna mano de pintura. Oyes a alguien roncar.\n");

  SetIntNoise("Se oye a alguien roncar.\n");
  SetIntSmell("Hmm.. quiza alguien deberia abrir una ventana para ventilar el pasillo.\n");
  SetLocate("ciudad de Zarkam");
  SetIndoors(1);
  SetIntBright(50);

  AddExit("norte",Z_POSADA("habitacion01"));
  AddExit("sur",Z_POSADA("habitacion04"));
  AddExit("este",Z_POSADA("pasillo02"));
}
