#include "path.h"
inherit KHA_ROOM;
create()
{
  ::create();
  SetIntShort("el Subnivel 3");
  SetIntLong(
    "Estas en una zona muy baja de las minas. Las paredes no estan tan bien\n"
    "cortadas como las de pisos superiores, y está muy mal iluminada.\n"
    );
  SetIndoors(1);
  SetIntBright(20);
  SetIntSmell(
    "Hueles a tierra y a metal.\n"
    );
  SetIntNoise(
    "Oyes golpes de pico a lo lejos y algun que otro grito de vez en cuando.\n"
    );
  AddExit("este",MPISO3+"nivel3-8");
  AddExit("suroeste",MPISO3+"nivel3-10");
  SetLocate("");
}
