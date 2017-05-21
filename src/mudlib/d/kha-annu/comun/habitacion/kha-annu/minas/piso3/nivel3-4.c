#include "path.h"
inherit KHA_ROOM;
create()
{
  ::create();
  SetIntShort("el Subnivel 3");
  SetIntLong(
    "Estas en una zona muy baja de las minas. Las paredes no estan tan\n"
    "bien cortadas como las de pisos superiores, y no esta tan bien iluminada.\n"
    );
  SetIndoors(1);
  SetIntBright(30);
  SetIntSmell(
    "Hueles a tierra y a metal.\n"
    );
  SetIntNoise(
    "Oyes golpes de pico a lo lejos y algun que otro grito de vez en cuando.\n"
    );
  AddExit("noroeste",MPISO3+"nivel3-3");
  AddExit("este",MPISO3+"nivel3-5");
  SetLocate("");
}