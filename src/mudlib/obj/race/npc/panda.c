/* SIMAURIA '/obj/race/npc/panda.c'
   ================================
   [w] Woo@simauria

   24-02-99 [w] Creación de este archivo como prueba. Este archivo no
                varia mucho del de las razas normales, salvo que no
                tiene SetHome ni AddEquipment ni SetRaceDescription.
   20-10-99 [w] Modificada su descripción.
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
  SetAlign  (300);
  SetMaxFood   (250);
  SetMaxDrink  (250);
  SetMaxAlcohol    (10);
  SetWeight (250000);
  SetSize(P_SIZE_LARGE);
  AddHand("garra derecha", DT_SLASH, 4); // No puede empuñar armas
  AddHand("garra izquierda", DT_SLASH, 4);
  SetStatBonus(P_CON,8);
  SetStatBonus(P_DEX,-6);
  SetStatBonus(P_INT,-10);
  SetStatBonus(P_STR,8);
  SetIVision(- MAX_SUNBRIGHT/2 );
  SetUVision(MAX_SUNBRIGHT);
  SetLong("\
Se trata de un precioso panda de color blanco y negro.\n");
}
