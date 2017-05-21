/* SIMAURIA '/obj/race/npc/ardilla.c'
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
  SetAlign  (100);
  SetMaxFood   (120);
  SetMaxDrink  (140);
  SetMaxAlcohol    (5);
  SetWeight (12000);
  SetSize   (P_SIZE_SMALL);
  AddHand   ("pata delantera derecha", DT_BLUDGEON, 1);
  AddHand   ("pata delantera izquierda", DT_BLUDGEON, 1);
  SetStatBonus   (P_CON,-3);
  SetStatBonus   (P_DEX,3);
  SetStatBonus   (P_INT,2);
  SetStatBonus   (P_STR,-2);
  SetIVision(- MAX_SUNBRIGHT );
  SetUVision(MAX_SUNBRIGHT);
  SetLong("\
Es una pequeña ardilla de color castaño con una larga cola. Parece un animal\n\
bastante insignificante pero tiene una gran movilidad.\n");
}
