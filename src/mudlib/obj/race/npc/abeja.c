/* SIMAURIA '/obj/race/npc/abeja.c'
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
  SetAlign  (0);
  SetMaxFood   (50);
  SetMaxDrink  (50);
  SetMaxAlcohol    (50);
  SetWeight (10);
  SetSize(P_SIZE_SMALL);
  AddHand("un aguijón", DT_PIERCE,1);
  SetStatBonus(P_CON,-5);
  SetStatBonus(P_DEX,4);
  SetStatBonus(P_INT,4);
  SetStatBonus(P_STR,-3);
  SetIVision(- MAX_SUNBRIGHT/2 );
  SetUVision(MAX_SUNBRIGHT);
  SetLong("\
Es una abeja con un aguijón que asusta.\n");
}
