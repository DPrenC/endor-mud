// Libreria de Armas de Simauria.
// Elaborada por [Gw]Greywolf, usando objetos creados por
// Woo, Angor, Nemesis, Kodex, Izet, Kintups y todos aquellos
// que han hecho algun arma en el mud. Gracias a ellos por
// su esfuerzo. Tambien son añadidas varias armas nuevas.
// Arma: Vara de madera
// Fichero: vara.c
// Fecha de creación: 22/11/04 [Gw]

#include <mud.h>
#include <combat.h>
#include <properties.h>

inherit WEAPON;


create() {
  ::create();
  SetStandard(WT_VARA, 4, P_SIZE_MEDIUM, M_MADERA);
  SetAds(({"una","larga"}));
  SetIds(({"arma","vara"}));
  SetShort("una vara");
  SetLong("Una larga vara de roble usada para golpear.\n");
  SetWeight(2000);
  SetNumberHands(1);
  Set(P_GENDER,GENDER_FEMALE);


}
