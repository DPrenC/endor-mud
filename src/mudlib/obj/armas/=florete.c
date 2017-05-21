// Libreria de Armas de Simauria.
// Elaborada por [Gw]Greywolf, usando objetos creados por
// Woo, Angor, Nemesis, Kodex, Izet, Kintups y todos aquellos
// que han hecho algun arma en el mud. Gracias a ellos por
// su esfuerzo. Tambien son añadidas varias armas nuevas.
// Arma: Florete
// Fichero: florete.c
// Fecha de creación: 22/11/04 [Gw]

#include <mud.h>
#include <combat.h>
#include <properties.h>

inherit WEAPON;

create() {
::create();
   SetStandard(WT_ESGRIMA, 6, P_SIZE_MEDIUM, M_ACERO);
   SetShort("un lujoso florete");
   SetLong("Es un florete de hoja larga y punta afilada. La hoja brilla con un reflejo\n"
           "azulado y la guarda está guarnecida de piedras preciosas.\n");
   AddId(({"florete","lujoso florete"}));
   SetNumberHands(1);
   SetWeight(1500);
}
