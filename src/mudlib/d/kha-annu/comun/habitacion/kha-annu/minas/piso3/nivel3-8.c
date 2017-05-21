#include "path.h"
inherit KHA_ROOM;
create()
{
  ::create();
  SetIntShort("el Subnivel 3");
  SetIntLong(
    "Estas en una zona muy baja de las minas. Las paredes no estan tan bien\n"
    "cortadas como las de pisos superiores, y no esta tan bien iluminada.\n"
    );
  SetIndoors(1);
  SetIntBright(30);
  SetIntSmell(
    "Hueles a tierra y a metal.\n"
    );
  SetIntNoise(
    "Oyes golpes de pico a lo lejos y algun que otro grito de vez en cuando.\n"
    );
  AddExit("norte",MPISO3+"nivel3-7");
  AddExit("oeste",MPISO3+"nivel3-9");
AddExit("abajo",MPISO4+"nivel4-1");
  SetLocate("");
}
