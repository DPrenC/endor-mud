/*
DESCRIPCION  : La raza básica de orcos, tamaño medio, los utilizados en masa por Sauron y Saruman.
FICHERO      : /obj/race/base/orco.c
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

  SetAlign  (-50);
  SetMaxFood   (120);
  SetMaxDrink  (85);
  SetMaxAlcohol    (120);
  SetWeight (76000);
  SetSize(P_SIZE_MEDIUM);
  SetBando(P_BANDO_OSCURIDAD);
  AddHand("garra derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("garra izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus(P_CON,  1);
  SetStatBonus(P_DEX, -1);
  SetStatBonus(P_INT,  -2);
  SetStatBonus(P_STR,  1);
SetResistance(DT_FIRE,25);
SetResistance(DT_COLD,5);
SetResistance(DT_GAS,15);
SetResistance(DT_NOAIR,15);
SetResistance(DT_WATER,-40);
  SetIVision(-(MAX_SUNBRIGHT / 2));
  SetUVision(MAX_SUNBRIGHT);
  SetLong(
"@@Nombre@@ es un orco. Su mugriento pelaje es como terciopelo negro. Un par de\n\
largos colmillos salen de la boca de @@Nombre@@. Su mirada demuestra\n\
inteligencia, pero su aspecto es peligroso.\n");
  SetRaceDescription (
  "Esta inmunda raza fue concebida en la noche de los tiempos Por Morgoth, aunque no se "
  "sabe bien a partir de que cepa.\n"
  "Algunos sostienen que fueron elfos torturados y pervertidos por el Poder Oscuro, "
  "otros cuentan que fueron los hombres quienes dieron origen a estas criaturas y "
  "otros, que nacieron a partir de una mezcolanza de distintas cepas.\n"
  "En general, los Orcos y sus distintas variantes son criaturas malévolas, crueles, "
  "taimadas, que viven en tribus dominadas por la violencia,  dirigidas por sus más "
  "fuertes guerreros y donde los débiles perecen y solo aquel con capacidad para "
  "defenderse sobrevive.\n"
  "Todo orco es adicto al combate y  la violencia, y para ellos la guerra es la más "
  "gloriosa de las ocupaciones, aunque el robo, el asesinato a traición, la tortura, "
  "comer y beber son actividades así mismo muy respetadas.\n");

}
