/*  

Por [F] Fran@simauria  

       17 nov 1999

*/

#include "path.h"

inherit KHA_ROOM;

create()
{
  ::create();
  SetIntShort("el Subnivel 2");
  SetIntLong(
    "Estás en el subnivel 2, no hay lámparas, pero se ve con la luz de las lámparas anteriores y\n"
    "las que hay mas adelante.\n"
    );
  SetIndoors(1);
  SetIntBright(50);
  SetIntSmell(
    "Hueles a tierra y a metal.\n"
    );
  SetIntNoise(
    "Oyes golpes de pico a lo lejos y algun que otro grito de vez en cuando.\n"
    );
  AddExit("noroeste",MPISO2+"bifne2se3");
  AddExit("suroeste",MPISO2+"bifse2se");
  SetLocate("");
}