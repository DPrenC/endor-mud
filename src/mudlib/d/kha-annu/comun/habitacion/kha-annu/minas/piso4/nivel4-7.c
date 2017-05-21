#include "path.h"
inherit KHA_ROOM;
create()
{
  ::create();
  SetIntShort("el subnivel 4");
  SetIntLong(
    "Te encuentras muy abajo en los túneles... en este tramo en el que estas,\n"
    "sientes como tu cabeza toca cosas que tus ojos no querrian ver... rezas\n"
    "por que no sean cosas que se muevan, pues seguro que cualquier cosa que\n"
    "viva por aqui tiene muy mala leche...\n"
    );
  SetIndoors(1);
  SetIntBright(0);
  SetIntSmell(
    "Huele a tierra mojada.\n"
    );
  SetIntNoise(
    "Oyes como de vez en cuando alguna piedra y algo de tierra se desploma del techo.\n"
    );
  AddExit("oeste",MPISO4+"nivel4-6");
  AddExit("sur","nivel4-8");
  AddExit("este",MPISO4+"nivel4-9");
  SetLocate("");
}
