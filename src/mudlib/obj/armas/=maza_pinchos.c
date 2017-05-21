// Libreria de Armas de Simauria.
// Elaborada por [Gw]Greywolf, usando objetos creados por
// Woo, Angor, Nemesis, Kodex, Izet, Kintups y todos aquellos
// que han hecho algun arma en el mud. Gracias a ellos por
// su esfuerzo. Tambien son añadidas varias armas nuevas.
// Arma: Maza de pinchos
// Fichero: maza_pinchos.c
// Fecha de creación: 22/11/04 [Gw]

#include <mud.h>
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_MAZA, 6, P_SIZE_MEDIUM, M_ACERO);
   SetShort("una maza de pinchos");
   SetLong("Es una maza metálica cubierta de puntiagudos pinchos.\n");
   AddId(({"maza de pinchos"}));
   SetWeight(2);
   SetNumberHands(1);
   Set(P_GENDER,GENDER_FEMALE);
}
