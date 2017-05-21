/*
DESCRIPCION  : un enano barbafuego, originario de las monta�as Azules.
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
  "algo m�s clara que la de otros clanes, y una larga e irsuta melena del color "
  "del fuego  se desparrama sobre sus anchos hombros y fornida espalda.\n"
  "Su rostro, de expresi�n ce�uda, posee las facciones anchas propias de los Enanos, "
  "destacando sus chispeantes ojos azules que miran de forma retadora y desconfiada.\n"
  "En general, @@Nombre@@ da la impresi�n de ser @@ind@@ individu@@suf@@ de talante "
  "suspicaz y cuya ira es f�cil de despertar y muy dif�cil de apagar.\n");
  
  SetRaceDescription(
  "El clan de los Barbafuego o Barbafogosas son el pueblo del Padre Enano que despert� "
  "junto al Monte Dolmed, en la parte central de las Monta�as Azules de anta�o.\n"
  "Este clan fund� el reino de Tumunzahar, llamado por los Elfos Nogrod o Morada Hueca.\n"
  "Fue su ej�rcito  el que atac� Doriath, por lo cual se enemistaron para siempre con "
  "los Elfos, y sus grandes armeros como Telchar o Gamil Zirak quienes forjaron "
  "poderosas armas de gran renombre como la espada Narsil y joyas como el Nauglam�r.\n" 
  "En los tumultos y terremotos ocurridos a finales de la Primera Edad, en los d�as de "
  "la guerra de la C�lera, su fortaleza qued� arruinada y la mayor�a de los "
  "supervivientes abandonaron sus tierras y marcharon al exilio al reino de los "
  "Barbiluengos, Kh�zad-D�m.\n"
  "Tras la ruina de esta �ltima gran mansi�n, al igual que los Barbiluengos, los "
  "Barbafuego se convirtieron en un clan errante y poco numeroso que en muchas "
  "ocasiones uni� sus esfuerzos y destinos a los de los otros clanes errantes.\n"
  "Muy menguados en n�mero, son tenidos por magn�ficos herreros, a�n entre los Enanos, "
  "y por un talante ardoroso y dado a la c�lera f�cil, aunque son guerreros temibles.\n"
  "Se los puede distinguir por su piel algo m�s clara, ojos azules o verdes y pelo y barbas "
  "pelirrojas, que lucen largas y esplendorosas,  de donde el clan toma su nombre.\n");
}