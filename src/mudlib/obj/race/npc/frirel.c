/* SIMAURIA '/obj/race/npc/frirel.c'
   =================================
   [w] Woo@simauria

   NOTA: Esta raza pertenece al gremio de las amazonas para cualquier
         modificación notificarlo a woo.

   16-02-00 [w] Elemental de Fuego.
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
  SetMaxFood   (320);
  SetMaxDrink  (350);
  SetMaxAlcohol    (10);
  SetWeight (50000);
  SetSize   (P_SIZE_MEDIUM);
  AddHand   ("una llamarada",  TD_CALOR, 5); // No puede empuñar armas
  AddHand   ("una llamarada",  TD_CALOR, 5);
  SetResistance(TD_CALOR,100); //inmune al fuego
  SetResistance(TM_CALOR,100); //inmune al fuego
  SetResistance(TD_FRIO,-100); //el frio le daña el doble
  SetResistance(TM_FRIO,-100); //el frio le daña el doble
  SetStatBonus(P_CON,0); //constitucion normal
  SetStatBonus(P_DEX,7);	//el fuego es mur rapido...
  SetStatBonus(P_INT,-5);//poco listo
  SetStatBonus(P_STR,-2);//poco fuerte (joder, si no tiene masa!!)
  SetIVision(- MAX_SUNBRIGHT );
  SetUVision(MAX_SUNBRIGHT); // Tienen buena visión
  SetLong("\
Es un ser de fuego cuya forma te recuerda vagamente a un humano de estatura\n\
mediana. Desprende un enorme calor que te impide acercate excesivamente a él.\n");
}