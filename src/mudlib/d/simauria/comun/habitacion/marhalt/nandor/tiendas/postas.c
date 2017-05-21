#include <mud.h>
#include "./path.h"

inherit SIM_ROOM;
create () {
  ::create();
SetLocate("Aldea de Nandor");
SetIntNoise("Oyes mucho jaleo.\n");
SetIntSmell("Huele a cola.\n");
SetIntShort("la casa de Postas");
SetIntLong(
"Que jaleo! Esta es la sala de postas de Nandor, pero parece que aun "
"esta en construccion, asi que deberas esperar algun tiempo antes de que "
"puedas usar sus servicios.\n");
SetIndoors(1);
SetIntBright(30);

AddExit("norte","../calle0" );

}
