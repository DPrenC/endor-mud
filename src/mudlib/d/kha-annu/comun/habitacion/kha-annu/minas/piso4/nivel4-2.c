#include "path.h"
inherit KHA_ROOM;
create()
{
  ::create();
  SetIntShort("el subnivel 4");
  SetIntLong(
    "Te encuentras muy abajo en los túneles...en una zona que no esta muy bien\n"
    "escabada aun.Parece que en esta zona no se han puesto apuntalamientos de\n"
    "seguridad, lo cual te hace sentir intranquilo.\n"
    );
  SetIndoors(1);
  SetIntBright(15);
  SetIntSmell(
    "Huele a tierra.\n"
    );
  SetIntNoise(
    "Oyes como de vez en cuando alguna piedra y algo de tierra se desploma del techo.\n"
    );
  AddExit("oeste",MPISO4+"nivel4-1");
  AddExit("este",MPISO4+"nivel4-3");
  SetLocate("");
}
