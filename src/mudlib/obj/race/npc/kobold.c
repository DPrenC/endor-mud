/* SIMAURIA '/obj/race/npc/kobold.c'
   ================================
   [g] gorthem@simauria


   29-9-00 [g] Modificada su descripción.
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
  SetMaxFood   (100);
  SetMaxDrink  (100);
  SetMaxAlcohol    (30);
  SetWeight (50000);
  SetSize   (P_SIZE_MEDIUM);
  AddHand   ("mano derecha", 0, WEAPON_CLASS_OF_HANDS); // No puede empuñar armas
  AddHand   ("mano izquierda", 0, WEAPON_CLASS_OF_HANDS);
  SetStatBonus   (P_CON,2);
  SetStatBonus   (P_DEX,2);
  SetStatBonus   (P_INT,0);
  SetStatBonus   (P_STR,2);
  SetIVision(-300);
  SetUVision(50);
  SetLong("\
Es un pequeño ser con ojos saltones y colmillos afilados que te mira como si\n\
pudieras ser su cena. No mas alto que un enano, este ser humanoide, feo y rojizo\n\
puede ser peligroso si sus amigos andan cerca.\n");
}
