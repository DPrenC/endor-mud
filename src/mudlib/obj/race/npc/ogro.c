/* [Nyh]
DESCRIPCION  : un ogro
FICHERO      : /obj/race/npc/ogro.c
--------------------------------------------------------------------------------
*/

#include <combat.h>
#include <config.h>
#include <attributes.h>
#include <nightday.h>
#include <properties.h>
inherit "/obj/raceobj";

public void create_blueprint()
{
  ::create_blueprint();

  SetAlign  (-200);
  SetMaxFood   (500);
  SetMaxDrink  (300);
  SetMaxAlcohol    (1100);
  SetWeight (280000);
  SetSize(P_SIZE_LARGE);

  AddHand("garra derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("garra izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus(P_CON,  4); /* bastante resistentes */
  SetStatBonus(P_DEX, -2); /* no muy agiles */
  SetStatBonus(P_INT,-12); /* pueden aprender magia */
  SetStatBonus(P_STR, 10); /* fuerza brutal */
  SetIVision(-(MAX_SUNBRIGHT / 2));
  SetUVision(MAX_SUNBRIGHT);
  SetLong("Un ogro, un gigantesco bruto de casi 3 metros de altura. "
          "Tiene una piel gruesa cubierta por oscuros bultos verrugosos, "
          "viste pieles malolientes y su cabello es largo, "
          "grasiento y desaseado.\n");
}
