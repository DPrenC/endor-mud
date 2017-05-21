/*
DESCRIPCION  : mezcla repulsiva entre orco y hombres, normalmente dunlendinos, usados 
por Saruman como espías en eriador.
FICHERO      : /obj/race/base/medio-orco.c
--------------------------------------------------------------------------------
*/

#include <combat.h>
#include <config.h>
#include <attributes.h>
#include <nightday.h>
#include <properties.h>
#include <bandos.h>
inherit "/obj/raceobj";

create_blueprint()
{
  ::create_blueprint();

  SetAlign  (-10);
  SetMaxFood   (105);
  SetMaxDrink  (90);
  SetMaxAlcohol    (105);
  SetWeight (75000);
  SetSize(P_SIZE_LARGE);
  SetBando(P_BANDO_OSCURIDAD);
  AddHand("áspera mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("áspera mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus(P_CON,  1);
  SetStatBonus(P_DEX, 0);
  SetStatBonus(P_INT,  0);
  SetStatBonus(P_STR,  0);
    SetStatBonus("Cha",  0);
      SetStatBonus(P_WIS,  0);
SetResistance(DT_FIRE,5);
SetResistance(DT_COLD,1);
SetResistance(DT_GAS,5);
SetResistance(DT_NOAIR,5);
SetResistance(DT_WATER,-2);
                  
  SetIVision(-(MAX_SUNBRIGHT / 2));
  SetUVision(MAX_SUNBRIGHT);
  SetLong(
"@@Nombre@@ es @@ind@@ Medioorco, el perverso producto de la unión entre hombres y orcos.\n"
"Ronda el metro setenta y cinco de altura y pesará en torno a los ochenta kilos.\n"
"Su aspecto y constitución son los de un humano común, aunque su rostro cetrino y "
"achatado, así como sus ojos, pequeños, muy juntos y huidizos, bajo un ceño algo "
"prominente,recuerdan vagamente a la tornadiza mirada de un trasgo.\n"
"Su piel, mas áspera y ligeramente más gruesa de lo habitual en un humano, tiene un tono "
"cetrino y sus gestos y actitud son solapados y furtivos.\n");
SetRaceDescription(
"Los medio-orcos son  escasos en número y  pasan casi inadvertidos como raza o pueblo.\n"
"Surgieron a fines de la Tercera Edad, cuando Saruman comenzó a hacerse fuerte en "
"Isengard y reclutar toda clase de criaturas malignas.\n"
"siendo fruto del cruce de Orcos con mujeres dunlendinas, están en su mayoría al "
"servicio de Isengard en cuerpo y alma, pues Orcos y Hombres los desprecian y repudian por igual.\n"
"Son muy apreciados como exploradores y sobretodo espías, pues se mezclan sin dificultad "
"con los hombres de Eriador.\n");
}