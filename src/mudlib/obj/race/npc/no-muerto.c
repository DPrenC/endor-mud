/* SIMAURIA '/obj/race/npc/no-muerto.c'
   ====================================
   [h] Nyh@simauria

   15-06-03 [h] Creación
*/

#include <config.h>
#include <attributes.h>
#include <nightday.h>
#include <races.h>
#include <combat.h>
#include <properties.h>
inherit "/obj/raceobj";

public void create_blueprint() {
  ::create_blueprint();
  SetAlign  (-500);
  SetMaxFood   (99999); //no comen
  SetMaxDrink  (99999); //no beben
  SetMaxAlcohol    (99999); //no se emborrachan
  SetWeight (10000);
  SetSize(P_SIZE_MEDIUM);
  AddHand("garra derecha", 0, 2);
  AddHand("garra izquierda", 0, 2);
  SetLong("@@Nombre@@ es un maldito no-muerto.\n");

  SetResistance(MT_COLD, 100);
  SetResistance(DT_COLD, 100);
  SetResistance(MT_POISON, 100);
  SetResistance(DT_POISON, 100);
  SetResistance(DT_GAS, 100);
  SetResistance(MT_GAS, 100);
  SetResistance(DT_NOAIR, 100);
  SetResistance(MT_NOAIR, 100);

  SetResistance(DT_FIRE,-20);
  SetResistance(MT_FIRE,-20);

  SetResistance(DT_PSYCHO, 100);
  SetResistance(MT_PSYCHO, 100);

  SetResistance(DT_PIERCE, 50); // Los ataques de penetracion y corte les
  SetResistance(MT_PIERCE, 50); // hacen la mitad de daño...
  SetResistance(DT_SLASH,  50); //
  SetResistance(MT_SLASH,  50); //


}
