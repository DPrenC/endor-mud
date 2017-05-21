/* Espada de Belthain.
   Una vez devuelta a su dueño estará resuelto el quest.
   [Woo] Modificada
*/

#include <combat.h>
#include <properties.h>
#include <materials.h>
inherit WEAPON;

create() {
   ::create();
   SetStandard(WT_ESPADA,4,P_SIZE_MEDIUM,M_ORO);
   SetShort("una espada de oro");
   SetLong("\
Es una espada hecha completamente de oro, con piedras preciosas en la empunyadura.\n\
Seguramente pertenezca a un gran senyor perteneciente a la nobleza.\n"
   );
   SetWeight(6000);
  Set(P_NOGIVE, 1);
  Set(P_NODROP, 1);
  Set(P_NOSELL, 1);
   SetNumberHands(2);
   SetIds( ({"espada","espada de oro","espada_de_belthain"}) );
   SetAds( ({"la","una"}) );
}
