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
"@@Nombre@@ es @@ind@@ enan@@suf@@. Es de un tama�o menor al de un humano, pero\n"
"parece m�s fuerte. Tiene una mirada severa y decidida, sin duda reflejo de un\n"
"car�cter constante y luchador. Supones que como los de su raza debe tener\n"
"debilidad por las piedras preciosas y especialmente por el oro.\n");

  SetRaceDescription(
  "Los enanos son una raza antigua, orgullosa y tenaz.\n"
  "Creados por el vala Aul� el Herrero que ansiaba la llegada de Hombres y Elfos, "
  "fueron bendecidos por Eru, que los acept� como hijos adoptivos con la condici�n de "
  "que durmieran hasta el tiempo en que los Elfos hubieran despertado.\n"
  "En tiempos remotos los Siete Padres de la raza enana se dispersaron por la Tierra "
  "Media y fundaron reinos propios.\n"
  "El Primer Padre y el m�s importante fue Durin, que fund� Khazad-D�m en las "
  "monta�as Nubladas, llamada m�s tarde Moria, y cuyo pueblo fue el que m�s intervino en "
  "los principales hechos de la historia de la Tierra media.\n"
  "Los enanos son un pueblo de baja estatura, anchas espaldas, manos y pies grandes, "
  "gran robustez y una fuerza y resistencia considerables, y habitualmente lucen "
  "largas barbas.\n"
  "Son longevos pues viven en torno a los dos siglos y medio.\n"
  "Soportan con facilidad las condiciones extremas, tanto el calor como el fr�o, y "
  "pueden llevar grandes cargas durante largas y agotadoras marchas sin necesidad de "
  "descanso.\n"
  "Es un pueblo orgulloso y tenaz y ni por el miedo ni por el poder es posible "
  "doblegarlos o esclavizarlos.\n"
  "Son maestros en la canter�a, la miner�a, la orfebrer�a, y la herrer�a y sus "
  "ciudades y fortalezas se sit�an en el interior de las grandes cordilleras monta�osas.\n"
  "Aprecian por encima de todo las cosas materiales y las obras de sus h�biles manos,  "
  "amando y deseando el oro por encima de toda otra cosa, aunque aprecian tambi�n "
  "cualquier otro metal o piedra preciosa, siendo legendarios sus tesoros, lo que les ha "
  "valido la enemistad con otras razas y la indeseable atenci�n de criaturas malignas y "
  "terribles como los dragones.\n"
  "Los siete clanes o casas de los enanos son: "
  "Barbiluengos, Barbafuegos, Barbatiesas, Piep�treos, Pu�of�rreos, Rizosnegros y "
  "Cinturas Anchas.\n");
}

