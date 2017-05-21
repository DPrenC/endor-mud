#include "path.h"
inherit LAD_ROOM;

create(){
  ::create();
  SetIntLong("Estas en un islote, el Corazon del Bosque.\n");
  SetIntShort("un islote");
  SetIntNoise("Escuchas el sonido del oleaje.\n");
  SetIntSmell("Huele a vegetacion y a humedad.\n");
  SetLocate("el islote de la cueva de Atbalnin");
  SetIndoors(1);
  SetIntBright(20);
}
