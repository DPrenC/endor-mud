/*
DESCRIPCION  : Ayuntamiento
FICHERO      : /d/akallab/comun/habitacion/akallab/azzor/narad/ayto.c
MODIFICACION : 15-02-99 [Angor@Simauria] Creacion
--------------------------------------------------------------------------------
*/

#include "path.h"
#include AK_MACRO
inherit ROOM;

create() {
  ::create();
 SetIntShort("el ayuntamiento del pueblo de Narad");
  SetIntLong(
  "Te encuentras en el ayuntamiento del pueblo de Narad, que en realidad "
    "no es otra cosa que la casa del jefe del poblado. Es algo mayor que "
    "el resto de las casas y por ello es aqui donde se reune el consejo, "
    "formado por el jefe y varios habitantes representativos, para tomar "
    "decisiones o impartir justicia. Observas varios trofeos de caza "
    "colgados en las paredes y una gruesa alfombra en el suelo. Un "
    "generoso fuego arde en una gran chimenea caldeando el ambiente.\n");

  AddDetail(({"trofeos","paredes"}),
  "En las paredes del ayuntamiento hay colgadas las cabezas disecadas de "
    "algunos grandes animales. Supones que deben ser trofeos de caza del "
    "jefe del poblado.\n");

  AddDetail(({"alfombra","piel","piel de oso"}),
  "Tendida en el suelo hay una gran piel de oso que hace las veces de "
    "de alfombra.\n");

  AddDetail(({"chimenea"}),
  "La chimenea de piedra esta adosada a la casa. En ella arde un "
    "agradable fuego que calienta el ambiente.\n");

  AddDetail(({"pueblo","villa","Narad"}),
  "Narad es el nombre de este pueblo. Es un pequenyo pueblo situado "
    "en el noroeste del valle de Azzor, en su parte alta. Sus habitantes "
    "se dedican basicamente a la agricultura y a la destilacion de bebida. "
    "La cerveza y el vino de esta zona son bien conocidos en la region.\n");

 SetIntNoise("Oyes el fuego crepitar en la chimenea.\n");
 SetIntSmell("Hueles el olor que desprende la madera al quemarse.\n");
 SetLocate("villa de Narad");
 SetIndoors(1);
 SetIntBright(50);

 AddExit("sur",NARAD("calle01"));
 AddExit("este",NARAD("calle04"));
}
