// Libreria de Armas de Simauria.
// Elaborada por [Gw]Greywolf, usando objetos creados por
// Woo, Angor, Nemesis, Kodex, Izet, Kintups y todos aquellos
// que han hecho algun arma en el mud. Gracias a ellos por
// su esfuerzo. Tambien son añadidas varias armas nuevas.
// Arma: Katana
// Fichero: katana.c
// Fecha de creación: 22/11/04 [Gw]

#include <mud.h>
#include <combat.h>
#include <properties.h>

inherit WEAPON;


create()
{

 ::create();
 SetStandard(WT_ESPADA,7,P_SIZE_MEDIUM,M_ACERO);
 SetShort("una katana");
 AddId(({"espada","katana"}));
 SetAds(({"una","larga","afilada"}));
 SetNumberHands(1);
 SetLong("\
Es una espada de acero de mediano tamaño, estrecha, recta y muy afilada.\n");
 SetWeight(1000);
 Set(P_GENDER,GENDER_FEMALE);
}
