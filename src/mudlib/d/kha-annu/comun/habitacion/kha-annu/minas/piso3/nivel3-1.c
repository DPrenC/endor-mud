#include "path.h"
inherit KHA_ROOM;
create()
{
  ::create();
  SetIntShort("el Subnivel 3");
  SetIntLong(
    "Estas en una zona muy baja de las minas. Las paredes no estan tan bien\n"
    "cortadas como las de pisos superiores, y no esta tan bien iluminada.\n"
    "Por el suelo y paredes hay rocas sueltas.\n"
    );
  SetIndoors(1);
  SetIntBright(30);
  SetIntSmell(
    "Hueles a tierra y a metal.\n"
    );
  SetIntNoise(
    "Oyes golpes de pico a lo lejos y algun que otro grito de vez en cuando.\n"
    );
  AddDetail(({"piedras","piedra","roca","rocas"}),
    "Piedras y demas tipos de sedimentos rocosos que con el paso de los muchos siglos... hmm milenios....\n"
    "bueno, mogollon de años, se han transformado en muchos tipos de ... Piedras... si piedras... que esperabas... si fuera Oro, esto estaria lleno de Enanos!\n"
    );
  AddExit("este",MPISO3+"nivel3-2");
AddExit("arriba",MPISO2+"bifse2se1");
  SetLocate("");
}
