/*
DESCRIPCION  : un enano
FICHERO      : /obj/race/base/enano.c
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
  SetMaxAlcohol(200);
  SetWeight(75000);
  SetSize(P_SIZE_MEDIUM);
  SetBando(P_BANDO_LUZ);
  AddHand("callosa mano derecha", 0, WEAPON_CLASS_OF_HANDS*2);
  AddHand("callosa mano izquierda", 0, WEAPON_CLASS_OF_HANDS*2);

  SetStatBonus(P_CON,3);
  SetStatBonus(P_DEX,-3);
  SetStatBonus(P_INT,0);
  SetStatBonus(P_STR,2);
  SetResistance(DT_FIRE,20);
SetResistance(DT_COLD,10);
SetResistance(DT_GAS,5);
SetResistance(DT_POISON,5);
SetResistance(DT_PSYCHO,40);
SetResistance(DT_NOAIR,5);
SetResistance(DT_WATER,-35);
SetResistance(MT_WATER,-25);
                  SetResistance(DT_ACID,  5);
  SetIVision(-REL_STATE(ND_PRENOON, MAX_SUNBRIGHT));
  SetUVision(MAX_SUNBRIGHT);

  SetLong(
"@@Nombre@@ es @@ind@@ enan@@suf@@. Es de un tamaño menor al de un humano, pero\n"
"parece más fuerte. Tiene una mirada severa y decidida, sin duda reflejo de un\n"
"carácter constante y luchador. Supones que como los de su raza debe tener\n"
"debilidad por las piedras preciosas y especialmente por el oro.\n");

  SetRaceDescription(
  "Los enanos son una raza antigua, orgullosa y tenaz.\n"
  "Creados por el vala Aulë el Herrero que ansiaba la llegada de Hombres y Elfos, "
  "fueron bendecidos por Eru, que los aceptó como hijos adoptivos con la condición de "
  "que durmieran hasta el tiempo en que los Elfos hubieran despertado.\n"
  "En tiempos remotos los Siete Padres de la raza enana se dispersaron por la Tierra "
  "Media y fundaron reinos propios.\n"
  "El Primer Padre y el más importante fue Durin, que fundó Khazad-Düm en las "
  "montañas Nubladas, llamada más tarde Moria, y cuyo pueblo fue el que más intervino en "
  "los principales hechos de la historia de la Tierra media.\n"
  "Los enanos son un pueblo de baja estatura, anchas espaldas, manos y pies grandes, "
  "gran robustez y una fuerza y resistencia considerables, y habitualmente lucen "
  "largas barbas.\n"
  "Son longevos pues viven en torno a los dos siglos y medio.\n"
  "Soportan con facilidad las condiciones extremas, tanto el calor como el frío, y "
  "pueden llevar grandes cargas durante largas y agotadoras marchas sin necesidad de "
  "descanso.\n"
  "Es un pueblo orgulloso y tenaz y ni por el miedo ni por el poder es posible "
  "doblegarlos o esclavizarlos.\n"
  "Son maestros en la cantería, la minería, la orfebrería, y la herrería y sus "
  "ciudades y fortalezas se sitúan en el interior de las grandes cordilleras montañosas.\n"
  "Aprecian por encima de todo las cosas materiales y las obras de sus hábiles manos,  "
  "amando y deseando el oro por encima de toda otra cosa, aunque aprecian también "
  "cualquier otro metal o piedra preciosa, siendo legendarios sus tesoros, lo que les ha "
  "valido la enemistad con otras razas y la indeseable atención de criaturas malignas y "
  "terribles como los dragones.\n"
  "Los siete clanes o casas de los enanos son: "
  "Barbiluengos, Barbafuegos, Barbatiesas, Piepétreos, Puñoférreos, Rizosnegros y "
  "Cinturas Anchas.\n");
}

