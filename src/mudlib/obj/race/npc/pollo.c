/* SIMAURIA '/obj/race/npc/pollo.c'
   ================================
   [w] Woo@simauria

   20-10-99 [w] En mi af�n por incrementar el n�mero de razas de pnjs y
            porque lo voy a usar en un conjuro, pues aqu� un pollo.
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
  SetMaxFood   (100);
  SetMaxDrink  (100);
  SetMaxAlcohol    (5);
  SetWeight (7000);
  SetSize   (P_SIZE_SMALL);
  AddHand   ("pata derecha", DT_BLUDGEON, 1); // No puede empu�ar armas
  AddHand   ("pata izquierda", DT_BLUDGEON, 1);
  AddHand   ("pico", 1, 1);
  SetStatBonus   (P_CON,-4);
  SetStatBonus   (P_DEX,6);
  SetStatBonus   (P_INT,6);
  SetStatBonus   (P_STR,-10);
  SetIVision(- MAX_SUNBRIGHT );
  SetUVision(MAX_SUNBRIGHT); // Tienen buena visi�n
  SetLong("\
Se trata de un pollo peque�o y de color amarillo. Sus cortas plumas le\n\
protegen de la inclemencias clim�ticas y su pico resulta precioso.\n");
}
