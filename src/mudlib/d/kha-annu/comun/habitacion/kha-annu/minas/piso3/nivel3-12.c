#include "path.h"
inherit KHA_ROOM;
create()
{
  ::create();
  SetIntShort("el Subnivel 3");
  SetIntLong(
    "Estas en una zona muy baja de las minas. Las paredes no estan tan bien\n"
    "cortadas como las de pisos superiores, y casi no se ve.\n"
    );
  SetIndoors(1);
  SetIntBright(10);
  SetIntSmell(
    "Hueles a tierra y a metal.\n"
    );
  SetIntNoise(
    "Oyes golpes de pico a lo lejos y algun que otro grito de vez en cuando.\n"
    );
  AddExit("noreste",MPISO3+"nivel3-11");
  AddExit("sudeste",MPISO3+"nivel3-15");
  SetLocate("");
}
