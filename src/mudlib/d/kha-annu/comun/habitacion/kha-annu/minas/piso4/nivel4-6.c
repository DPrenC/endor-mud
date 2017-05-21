#include "path.h"
inherit KHA_ROOM;
create()
{
  ::create();
  SetIntShort("el subnivel 4");
  SetIntLong(
    "Te encuentras muy abajo en los túneles...esta zona en la que estas es\n"
    "solamente un agujero mal cortado, Te preguntas que demonios ganas tu\n"
    "arrastrandote por toda esta tierra aun a riesgo de morir aplastado...\n"
    "El túnel sigue pobremente hacia el este.\n"
    );
  SetIndoors(1);
  SetIntBright(0);
  SetIntSmell(
    "Huele a tierra.\n"
    );
  SetIntNoise(
    "Oyes como de vez en cuando alguna piedra y algo de tierra se desploma del techo.\n"
    );
  AddExit("noroeste",MPISO4+"nivel4-5");
  AddExit("este",MPISO4+"nivel4-7");
  SetLocate("");
}
