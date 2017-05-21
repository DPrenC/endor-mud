#include "path.h"
inherit KHA_ROOM;
create()
{
  ::create();
  SetIntShort("el subnivel 4");
  SetIntLong(
    "Te encuentras muy abajo en los túneles...en una zona que no esta muy bien\n"
    "escabada aun.Parece que en esta zona no se han puesto apuntalamientos de\n"
    "seguridad, pequeños trozos de tierra  caen sobre tu cabeza, nada grande,\n"
    "pero te preocupa...El túnel esta muy oscuro delante...\n"
    );
  SetIndoors(1);
  SetIntBright(10);
  SetIntSmell(
    "Huele a tierra.\n"
    );
  SetIntNoise(
    "Oyes como de vez en cuando alguna piedra y algo de tierra se desploma del techo.\n"
    );
  AddExit("noroeste",MPISO4+"nivel4-4");
  AddExit("sudeste",MPISO4+"nivel4-6");
  SetLocate("");
}
