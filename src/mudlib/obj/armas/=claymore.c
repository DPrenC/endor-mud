// Libreria de Armas de Simauria.
// Elaborada por [Gw]Greywolf, usando objetos creados por
// Woo, Angor, Nemesis, Kodex, Izet, Kintups y todos aquellos
// que han hecho algun arma en el mud. Gracias a ellos por
// su esfuerzo. Tambien son añadidas varias armas nuevas.
// Arma: Espada Claymore
// Fichero: claymore.c
// Fecha de creación: 22/11/04 [Gw]

#include <mud.h>
#include <combat.h>
#include <properties.h>

inherit WEAPON;


create() {
  ::create();
  SetStandard(WT_ESPADA, 8, P_SIZE_MEDIUM, M_ACERO);
  SetAds(({"una","tosca","pesada"}));
  AddId(({"claymore","arma","espada"}));
  SetShort("una claymore");
  SetLong(
"Es una pesada espada de hoja recta, de la que sobresalen dos largas hojas\n\
orientadas oblicuamente. En general parece algo tosca, pero es efectiva.\n");
  Set(P_GENDER,GENDER_FEMALE);
  SetWeight(2000);
  SetNumberHands(1);
}
