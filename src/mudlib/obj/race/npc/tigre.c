/* SIMAURIA '/obj/race/npc/tigre.c'
   ================================
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
  SetAlign  (50);
  SetMaxFood   (200);
  SetMaxDrink  (200);
  SetMaxAlcohol    (30);
  SetWeight (150000);
  SetSize   (P_SIZE_MEDIUM);
  AddHand   ("garra derecha", DT_SLASH, 4); // No puede empuñar armas
  AddHand   ("garra izquierda", DT_SLASH, 4);
  SetStatBonus   (P_CON,1);
  SetStatBonus   (P_DEX,1);
  SetStatBonus   (P_INT,-3);
  SetStatBonus   (P_STR,1);
  SetIVision(- MAX_SUNBRIGHT );
  SetUVision(MAX_SUNBRIGHT);
  SetLong("\
Es un feroz tigre de gran tamaño de pelaje amarillento y con rayas negras\n\
en el lomo y la cola.\n");
}
