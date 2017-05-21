/* ENDOR-MUD'/obj/race/npc/raton.c'
   =================================
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
  SetAlign  (0);
  SetMaxFood   (20);
  SetMaxDrink  (20);
  SetMaxAlcohol    (5);
  SetWeight (100);
  SetSize   (P_SIZE_SMALL);

	AddHand("sus diminutos dientecillos", TD_PENETRACION, 0);
  SetStatBonus   (P_CON,-3);
  SetStatBonus   (P_DEX,3);
  SetStatBonus   (P_INT,2);
  SetStatBonus   (P_STR,-3);
  SetStatBonus("Cha",0);
        SetStatBonus(P_WIS,0);
  SetIVision(- MAX_SUNBRIGHT );
  SetUVision(MAX_SUNBRIGHT);
  	SetLong("Es un pequeño ratón de inquieta y diminuta cola.\n"
	"Tiene ojillos negros y vivos como cuentas de azabache. Su movimiento es tan veloz "
	"que apenas puede seguírselo con la vista cuando se camufla en la sombra proyectada "
	"por los objetos mientras busca alimento.\n");
}
