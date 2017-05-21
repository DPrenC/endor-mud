#include "path.h"
inherit KHA_ROOM;
create()
{
  ::create();
  SetIntShort("el subnivel 4");
  SetIntLong(
    "Aqui se acaba este túnel, no hay mas que una pared de tierra con marcas de pico.\n"
    );
  SetIndoors(1);
  SetIntBright(0);
  SetIntSmell(
    "Huele a tierra.\n"
    );
  SetIntNoise(
    "Oyes como de vez en cuando alguna piedra y algo de tierra se desploma del techo.\n"
    );
  AddExit("norte",MPISO4+"nivel4-7");
  SetLocate("");
}
