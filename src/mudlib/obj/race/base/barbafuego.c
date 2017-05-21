/*
DESCRIPCION  : un enano barbafuego, originario de las montañas Azules.
FICHERO      : /obj/race/base/barbafuego.c
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
  SetAlign(8);
  SetMaxFood(115);
  SetMaxDrink(85);
  SetMaxAlcohol(200);
  SetWeight(77000);
  SetSize(P_SIZE_MEDIUM);
  SetBando(P_BANDO_LUZ);
  AddHand("callosa mano derecha", 0, WEAPON_CLASS_OF_HANDS*2);
  AddHand("callosa mano izquierda", 0, WEAPON_CLASS_OF_HANDS*2);

  SetStatBonus(P_CON,3);
  SetStatBonus(P_DEX,-3);
  SetStatBonus(P_INT,0);
  SetStatBonus(P_STR,2);
  SetStatBonus(P_WIS, 0);
SetStatBonus("Cha", -1);
  SetResistance(DT_FIRE,27);
SetResistance(DT_COLD,10);
SetResistance(DT_GAS,7);
SetResistance(DT_POISON,5);
SetResistance(DT_PSYCHO,40);
SetResistance(DT_NOAIR,7);
SetResistance(DT_WATER,-40);
SetResistance(MT_WATER,-30);
                  SetResistance(DT_ACID,  5);
  SetIVision(-REL_STATE(ND_PRENOON, MAX_SUNBRIGHT));
  SetUVision(MAX_SUNBRIGHT);

  SetLong(
  "@@Nombre@@ es @@ind@@ enan@@suf@@ del clan de los Barbafuego.\n"
  "Fornid@@suf@@, baj@@suf@@ y robust@@suf@@ como todos los de su raza, posee una piel "
  "algo más clara que la de otros clanes, y una larga e irsuta melena del color "
  "del fuego  se desparrama sobre sus anchos hombros y fornida espalda.\n"
  "Su rostro, de expresión ceñuda, posee las facciones anchas propias de los Enanos, "
  "destacando sus chispeantes ojos azules que miran de forma retadora y desconfiada.\n"
  "En general, @@Nombre@@ da la impresión de ser @@ind@@ individu@@suf@@ de talante "
  "suspicaz y cuya ira es fácil de despertar y muy difícil de apagar.\n");
  
  SetRaceDescription(
  "El clan de los Barbafuego o Barbafogosas son el pueblo del Padre Enano que despertó "
  "junto al Monte Dolmed, en la parte central de las Montañas Azules de antaño.\n"
  "Este clan fundó el reino de Tumunzahar, llamado por los Elfos Nogrod o Morada Hueca.\n"
  "Fue su ejército  el que atacó Doriath, por lo cual se enemistaron para siempre con "
  "los Elfos, y sus grandes armeros como Telchar o Gamil Zirak quienes forjaron "
  "poderosas armas de gran renombre como la espada Narsil y joyas como el Nauglamír.\n" 
  "En los tumultos y terremotos ocurridos a finales de la Primera Edad, en los días de "
  "la guerra de la Cólera, su fortaleza quedó arruinada y la mayoría de los "
  "supervivientes abandonaron sus tierras y marcharon al exilio al reino de los "
  "Barbiluengos, Khäzad-Dúm.\n"
  "Tras la ruina de esta última gran mansión, al igual que los Barbiluengos, los "
  "Barbafuego se convirtieron en un clan errante y poco numeroso que en muchas "
  "ocasiones unió sus esfuerzos y destinos a los de los otros clanes errantes.\n"
  "Muy menguados en número, son tenidos por magníficos herreros, aún entre los Enanos, "
  "y por un talante ardoroso y dado a la cólera fácil, aunque son guerreros temibles.\n"
  "Se los puede distinguir por su piel algo más clara, ojos azules o verdes y pelo y barbas "
  "pelirrojas, que lucen largas y esplendorosas,  de donde el clan toma su nombre.\n");
}