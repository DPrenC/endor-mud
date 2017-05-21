/*
DESCRIPCION  : un enano Piepétreo, originarios del sureste de las Orocarni.
FICHERO      : /obj/race/base/piepetreo.c
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
  SetAlign(10);
  SetMaxFood(115);
  SetMaxDrink(90);
  SetMaxAlcohol(190);
  SetWeight(78000);
  SetSize(P_SIZE_MEDIUM);
  SetBando(P_BANDO_NEUTRO);
  AddHand("callosa mano derecha", 0, WEAPON_CLASS_OF_HANDS*2);
  AddHand("callosa mano izquierda", 0, WEAPON_CLASS_OF_HANDS*2);

  SetStatBonus(P_CON,4);
  SetStatBonus(P_DEX,-4);
  SetStatBonus(P_INT,-1);
  SetStatBonus(P_STR,2);
  SetStatBonus(P_WIS, -1);
SetStatBonus("Cha", -2);
  SetResistance(DT_FIRE,20);
SetResistance(DT_COLD,10);
SetResistance(DT_GAS,5);
SetResistance(DT_POISON,10);
SetResistance(DT_PSYCHO,45);
SetResistance(DT_NOAIR,5);
SetResistance(DT_WATER,-35);
SetResistance(MT_WATER,-25);
                  SetResistance(DT_ACID,  10);
                  SetResistance(DT_SLASH,  1);
                  SetResistance(DT_BLUDGEON,  3);
                  SetResistance(DT_PIERCE, 1);
  SetIVision(-REL_STATE(ND_PRENOON, MAX_SUNBRIGHT));
  SetUVision(MAX_SUNBRIGHT);

  SetLong(
"@@Nombre@@ es @@ind@@ enan@@suf@@ del clan Piepétreo.\n"
"De constitución maciza y cuerpo robusto y achaparrado como todos los de su raza, "
"@@Nombre@@ destaca por su piel de un tono pétreo o grisáceo y por sus  cabellos de "
"color arenoso, que luce largos y algo desgreñados, desparramándose sobre sus hercúleos "
"hombros cuadrados, su amplio pecho y su musculosa espalda.\n"
"Su rostro, de expresión inexpresiva y en cierta manera indiferente es anguloso y severo, "
"y en sus ojos oscuros se percibe una mente lenta y reflexiva.\n");
SetRaceDescription(
"Los Piepétreo o Pies de Piedra son un clan descendiente de uno de los Grandes Padres "
"que despertó en las Orocarni.\n"
"Son el clan más silencioso, taciturno y reflexivo de todos.\n"
"Poco comunicativos y dados al contacto incluso con otros enanos, son lentos en tomar "
"decisiones, aunque una vez decididos nada ni nadie los podrá apartar de sus intenciones.\n"
"Fieles aliados e implacables enemigos, aunque con retraso siempre han acudido en "
"ayuda de otros clanes, aunque a parte de esto no suelen mezclarse en los conflictos de "
"otras razas ni salir de sus montañas.\n"
"Adoran por sobre otro material la piedra, cuyo aspecto recuerdan y nadie los ha "
"aventajado nunca en su trabajo y tallado.\n"
"Aunque no muy ricas ni opulentas, sus moradas son siempre bien construídas e "
"inespugnables, y sus artesanos conocen poderes que hacen que la materia de Arda se "
"pliegue a sus deseos.\n");
}