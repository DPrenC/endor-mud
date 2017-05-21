#include "path.h"
inherit LAD_ROOM;

create(){
  ::create();
  SetIntLong("Estas en una cueva un tanto oscura y tenebrosa.\n");
  SetIntShort("una cueva tenebrosa");
  SetIntNoise("Escuchas un apagado e incesante sonido de goteo.\n");
  SetIntSmell("Huele a moho y a humedad.\n");
  SetLocate("la cueva de Atbalnin");
  SetIndoors(1);
  SetIntBright(20);
}
