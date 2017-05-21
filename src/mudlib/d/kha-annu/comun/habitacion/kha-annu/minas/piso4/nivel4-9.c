#include "path.h"
inherit KHA_ROOM;
create()
{
  ::create();
  SetIntShort("el subnivel 4");
  SetIntLong(
    "Te encuentras muy abajo en los túneles...aqui hace mas frio del que\n"
    "normalmente hace. Este trozo de túnel esta aun peor acabado que el\n"
    "resto de este nivel... porque sera? Hay marcas en el suelo y en la pared\n"
    "y un agujero que da al este.\n"
    "Un escalofrio recorre tu espalda.\n"
    );
  SetIndoors(1);
  SetIntBright(0);
  SetIntSmell(
    "Huele a tierra.\n"
    );
  SetIntNoise(
    "Oyes como de vez en cuando alguna piedra y algo de tierra se desploma del techo.\n"
    );
  AddDetail(({"marcas","marca"}),
    "Son como de arañazos de picos, pero no tienen pinta de intentos de agrandar el túnel...\n"
    "mas bien son como al azar... es extraño, no?\n"
    );
  AddDetail(({"agujero"}),
    "Es un agujero que da al este...\n"
    );
  AddExit("oeste",MPISO4+"nivel4-7");
  AddExit("este",MPISO4+"nivel4-10X");
  SetLocate("");
}
