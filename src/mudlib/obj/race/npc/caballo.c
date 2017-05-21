/* SIMAURIA '/obj/race/npc/caballo.c'
   ==================================
   [w] Woo@simauria

   20-10-99 [w] Una nueva raza...
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
  SetAlign  (200);
  SetMaxFood   (220);
  SetMaxDrink  (240);
  SetMaxAlcohol    (15);
  SetWeight (130000);
  SetSize   (P_SIZE_LARGE);
  AddHand   ("pata delantera derecha", DT_BLUDGEON, 3);
  AddHand   ("pata delantera izquierda", DT_BLUDGEON, 3);
  SetStatBonus   (P_CON,0);
  SetStatBonus   (P_DEX,-2);
  SetStatBonus   (P_INT,2);
  SetStatBonus   (P_STR,0);
  SetIVision(- MAX_SUNBRIGHT );
  SetUVision(MAX_SUNBRIGHT);
  SetLong("\
Se trata de un caballo de color negro y con un pelaje muy brillante y liso.\n");
}
