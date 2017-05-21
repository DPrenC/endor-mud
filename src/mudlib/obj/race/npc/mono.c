/* SIMAURIA '/obj/race/npc/mono.c'
   ===============================
   [w] Woo@simauria

   20-10-99 [w] Nueva raza...
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
  SetMaxFood   (150);
  SetMaxDrink  (150);
  SetMaxAlcohol    (100);
  SetWeight (40000);
  SetSize(P_SIZE_MEDIUM);
  AddHand("mano derecha", 0, 1); // Si puede empuñar armas
  AddHand("mano izquierda", 0, 1);
  SetStatBonus(P_CON,-2);
  SetStatBonus(P_DEX,1);
  SetStatBonus(P_INT,4);
  SetStatBonus(P_STR,-3);
  SetIVision(- MAX_SUNBRIGHT/2 );
  SetUVision(MAX_SUNBRIGHT);
  SetLong("\
Es un mono de color marrón con una larga y peluda cola.\n");
}
