/* obj/race/slave
**
**  Jan-17-93 [Sique]
*/

#include <combat.h>
#include <config.h>
#include <attributes.h>
#include <nightday.h>

inherit "/obj/raceobj";

/*-------------------------------------------------------------------------*/

create_blueprint() {
  ::create_blueprint ();

  SetAlign  (0);
  SetMaxFood   (100);
  SetMaxDrink  (100);
  SetMaxAlcohol    (100);
  SetWeight (75000);
  AddHand   ("right hand", 0, WEAPON_CLASS_OF_HANDS);
  AddHand   ("left hand", 0, WEAPON_CLASS_OF_HANDS);

  SetLong(
  "@@Pl_Name@@ was kidnapped once by vikings and selled at a slave market\n" +
  "in Ireland. @@Pl_Pro@@ now need to work in a granite querry for the owner.\n");
  SetStatBonus   (P_CON, 0);
  SetStatBonus   (P_DEX, 0);
  SetStatBonus   (P_INT, 0);
  SetStatBonus   (P_STR, 2);
  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(3 * MAX_SUNBRIGHT);
  SetRaceDescription("Do you really want to become a slave? I don't mind.\n");

}

/***************************************************************************/
