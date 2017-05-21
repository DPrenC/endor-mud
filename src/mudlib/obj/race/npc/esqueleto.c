/* SIMAURIA '/obj/race/npc/esqueleto.c'
   ====================================
   [n] Nemesis@simauria

   24-02-99 [n] Creación de este archivo basado en el panda.
                de momento solo hereda el undead.c y poco mas.
   20-10-99 [w] No tiene que heredar el undead aquí, de hecho
                cuando tu cloneas un undead el pilla la raza
                y los valores de aquí, no al reves.
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
  SetAlign  (-500);
  SetMaxFood   (100);
  SetMaxDrink  (100);
  SetMaxAlcohol    (10);
  SetWeight (10000);
  SetSize(P_SIZE_MEDIUM);
  AddHand("garra derecha", 0, 2);
  AddHand("garra izquierda", 0, 2);
  SetStatBonus(P_CON,7);
  SetStatBonus(P_DEX,-7);
  SetStatBonus(P_INT,-7);
  SetStatBonus(P_STR,7);
  SetLong("@@Nombre@@ es un maldito esqueleto.\n");
}
