// Libreria de Armas de Simauria.
// Elaborada por [Gw]Greywolf, usando objetos creados por
// Woo, Angor, Nemesis, Kodex, Izet, Kintups y todos aquellos
// que han hecho algun arma en el mud. Gracias a ellos por
// su esfuerzo. Tambien son añadidas varias armas nuevas.
// Arma: Lucero del Alba
// Fichero: morning_star.c
// Fecha de creación: 22/11/04 [Gw]

#include <mud.h>
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_MANGUAL, 7, P_SIZE_MEDIUM, M_ACERO);
   SetShort("Un Lucero del Alba");
   SetLong("Es una bola metálica cubierta de puntiagudos pinchos unida a un mango\n\
por una cadena de acero.\n");
   AddId(({"lucero del alba","lucero"}));
   SetWeight(3000);
   SetNumberHands(1);
}
