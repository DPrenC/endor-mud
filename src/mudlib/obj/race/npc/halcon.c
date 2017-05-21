/* SIMAURIA '/obj/race/npc/halcon.c'
   =================================
   [w] Woo@simauria

   NOTA: Esta raza pertenece al gremio de las amazonas para cualquier
         modificaci�n notificarlo a woo.

   28-02-99 [w] Raza perteneciente a las mascotas de las amazonas.
   20-10-99 [w] Modificada la descripci�n.
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
  SetAlign  (20);
  SetMaxFood   (220);
  SetMaxDrink  (250);
  SetMaxAlcohol    (10);
  SetWeight (10000);
  SetSize   (P_SIZE_SMALL);
  AddHand   ("pata derecha", DT_SLASH, 1);
  AddHand   ("pata izquierda", DT_SLASH, 1);
  AddHand   ("pico", 3, 1);
  SetStatBonus   (P_CON,-4);
  SetStatBonus   (P_DEX,6);
  SetStatBonus   (P_INT,8);
  SetStatBonus   (P_STR,-10);
  SetIVision(- MAX_SUNBRIGHT );
  SetUVision(MAX_SUNBRIGHT); // Tienen buena visi�n
  SetLong("\
Es un peque�o halc�n cubierto de plumas de un color marr�n oscuro brillante\n\
y un largo pico.\n");
}
