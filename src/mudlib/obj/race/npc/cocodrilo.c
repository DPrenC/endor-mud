/* SIMAURIA '/obj/race/npc/cocodrilo.c'
   ====================================
   [w] Woo@simauria

   NOTA: Esta raza pertenece al gremio de las amazonas para cualquier
         modificación notificarlo a woo.

   07-03-99 [w] Raza perteneciente a las mascotas de las amazonas.
   20-10-99 [w] Modificada su descripción.
*/

#include <config.h>
#include <attributes.h>
#include <nightday.h>
#include <races.h>
#include <combat.h>
#include <properties.h>
inherit "/obj/raceobj";

public void create_blueprint()
{
  ::create_blueprint();
  SetAlign  (-100);
  SetMaxFood   (200);
  SetMaxDrink  (200);
  SetMaxAlcohol    (10);
  SetWeight (200000);
  SetSize   (P_SIZE_MEDIUM);
  AddHand   ("boca", DT_PIERCE, 5);
  AddHand   ("cola", DT_BLUDGEON, 3);
  SetStatBonus   (P_CON,3);
  SetStatBonus   (P_DEX,-3);
  SetStatBonus   (P_INT,-5);
  SetStatBonus   (P_STR,5);
  SetIVision(- MAX_SUNBRIGHT/2 );
  SetUVision(MAX_SUNBRIGHT);
  SetLong("\
Se trata de un peligroso cocodrilo de unos cinco metros de largo cubierto\n\
de escamas de color verdoso oscuro con manchas amarillento-rojizas. Tiene\n\
el hocico oblongo y una cola comprimida y con dos crestas laterales. Sus\n\
enormes dientes destacan en su boca.\n");
}
