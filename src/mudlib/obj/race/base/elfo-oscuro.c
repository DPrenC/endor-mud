/*
DESCRIPCION  : un elfo-oscuro
FICHERO      : /obj/race/base/elfo-oscuro.c
BASADO       : /obj/race/base/darkelf.c [mateese@nightfall] [cadra@nightfall]
--------------------------------------------------------------------------------
*/

#include <combat.h>
#include <config.h>
#include <attributes.h>
#include <nightday.h>
#include <properties.h>
inherit "/obj/raceobj";

create_blueprint()
{
  ::create_blueprint();
  SetAlign(-50);
  SetMaxFood(100);
  SetMaxDrink(100);
  SetMaxAlcohol(100);
  SetWeight(60000);
  SetSize(P_SIZE_MEDIUM);

  AddHand("mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus(P_CON,-4); // no son muy resistentes
  SetStatBonus(P_DEX,3); // mas agiles que los elfos
  SetStatBonus(P_INT,3); // no tan inteligentes como los elfos
  SetStatBonus(P_STR,-2); // no son muy fuertes
  SetIVision(-(2*MAX_SUNBRIGHT));
  SetUVision(REL_STATE(ND_PRENOON, MAX_SUNBRIGHT));
  SetLong(
"@@Nombre@@ es @@ind@@ elf@@suf@@-oscur@@suf@@. Aunque recuerda a @@ind@@ elf@@suf@@, su piel es de un\n\
blanco mortecino. Sus ojos, oscuros y profundos, son inquietantes y parecen\n\
esconder algun extraño proposito.\n");
  SetRaceDescription("\
Los elfos oscuros son parientes cercanos de los elfos. En tiempos remotos\n\
grupos de elfos que no pertenecian a las castas dominantes fueron seducidos\n\
por seres oscuros y malignos que les prometieron el poder que ansiaban.\n\
Fueron perseguidos por los elfos y huyeron encontrando refugio en las\n\
cuevas al otro lado del mar donde continuaron trabajando con los poderes\n\
de la oscuridad.\n\
Su apariencia cambio: son mas bajos y menos inteligentes que los elfos, pero\n\
a cambio son mas fuertes y agiles. Su piel es palida como la tiza. Suelen\n\
tener el pelo de color oscuro. La zona de piel en torno a sus ojos se ha\n\
oscurecido dando la impresion de unos ojos hundidos. Estos ojos son de color\n\
rojo oscuro y les permiten ver perfectamente en la oscuridad, pero son\n\
demasiado sensibles para la luz del sol.\n\
Son buenos luchadores y aunque no tan buenos como sus parientes en el arte\n\
de la magia, dominan la magia oscura.\n");
}
