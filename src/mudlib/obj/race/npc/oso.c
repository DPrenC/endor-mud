/* SIMAURIA '/obj/race/npc/oso.c'
   ==============================
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
  SetAlign  (-50);
  SetMaxFood   (250);
  SetMaxDrink  (250);
  SetMaxAlcohol    (50);
  SetWeight (400000);
  SetSize(P_SIZE_LARGE);
  AddHand("garra derecha", DT_SLASH, 4); // No puede empuñar armas
  AddHand("garra izquierda", DT_SLASH, 4);
  SetStatBonus(P_CON,9);
  SetStatBonus(P_DEX,-8);
  SetStatBonus(P_INT,-9);
  SetStatBonus(P_STR,8);
  SetIVision(- MAX_SUNBRIGHT/2 );
  SetUVision(MAX_SUNBRIGHT);
  SetLong("\
Es un feroz oso pardo de cabeza grande y unos ojos pequeños. Sus patas son\n\
fuertes y gruesas con cinco dedos en cada una. Tiene las uñas recias y\n\
ganchosas y la cola muy corta.\n");
}
