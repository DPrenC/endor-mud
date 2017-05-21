// Libreria de Armas de Simauria.
// Elaborada por [Gw]Greywolf, usando objetos creados por
// Woo, Angor, Nemesis, Kodex, Izet, Kintups y todos aquellos
// que han hecho algun arma en el mud. Gracias a ellos por
// su esfuerzo. Tambien son añadidas varias armas nuevas.
// Arma: Bardiche
// Fichero: bardiche.c
// Fecha de creación: 22/11/04 [Gw]

#include <mud.h>
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
  ::create();
  SetStandard(WT_HACHA, 12, P_SIZE_MEDIUM, M_ACERO);
  SetAds(({"una","pesada"}));
  SetIds(({"bardiche","arma","hacha"}));
  SetShort("una bardiche");
  SetLong(
"Es un gran hacha con una solida hoja de hierro de unos 80 cm de largo,\n\
empotrada en una larga asta de roble que mide casi 2 metros de largo.\n\
Es sin duda un arma efectiva en las manos adecuadas.\n");
  Set(P_GENDER,GENDER_FEMALE);
  SetWeight(7800);
  SetNumberHands(2);
}
