/* ENDOR-MUD'/obj/race/npc/conejo.c'
   =================================
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
  SetMaxFood   (20);
  SetMaxDrink  (20);
  SetMaxAlcohol    (5);
  SetWeight (2000);
  SetSize   (P_SIZE_SMALL);
  AddHand   ("pata delantera derecha", DT_BLUDGEON, 0);
  AddHand   ("pata delantera izquierda", DT_BLUDGEON,0 );
  SetStatBonus   (P_CON,-3);
  SetStatBonus   (P_DEX,3);
  SetStatBonus   (P_INT,2);
  SetStatBonus   (P_STR,-3);
  SetIVision(- MAX_SUNBRIGHT );
  SetUVision(MAX_SUNBRIGHT);
  SetLong("Es un conejo con el pelo muy espeso y de color gris. Sus orejas son tan largas"
" como su cabeza y las patas posteriores son más largas que las anteriores.\n");
}
