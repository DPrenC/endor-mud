/*
DESCRIPCION  : un enano Cinturaancha, originario de la parte central de 
las monta�as Azules.
FICHERO      : /obj/race/base/.cintura-ancha.c
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
  SetMaxFood(120);
  SetMaxDrink(90);
  SetMaxAlcohol(210);
  SetWeight(81000);
  SetSize(P_SIZE_MEDIUM);
  SetBando(P_BANDO_LUZ);
  AddHand("callosa mano derecha", 0, WEAPON_CLASS_OF_HANDS*2);
  AddHand("callosa mano izquierda", 0, WEAPON_CLASS_OF_HANDS*2);

  SetStatBonus(P_CON,3);
  SetStatBonus(P_DEX,-4);
  SetStatBonus(P_INT,0);
  SetStatBonus(P_STR,2);
  SetStatBonus(P_WIS, 0);
SetStatBonus("Cha", 1);
  SetResistance(DT_FIRE,20);
SetResistance(DT_COLD,15);
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
"@@Nombre@@ es @@ind@@ enan@@suf@@ del clan cinturaancha.\n"
"Es @@ind@@ individu@@suf@@ robust@@suf@@, de amplio contorno y constituci�n "
"achaparrada, incluso para ser @@ind@@ enan@@suf@@.\n"
"Su poderosa y rolliza constituci�n, grandes manos y pies y su rostro rubicundo le dan "
"un aspecto macizo e inamovible.\n"
"@@Nombre@@ es de piel clara, ligeramente rojiza, su cabello es rubio, liso y cae "
"abundante sobre sus fornidos hombros y su ancha y musculosa espalda.\n"
"Su rostro, de facciones m�s redondeadas y opulentas de lo habitual en los enanos, es "
"afable, aunque de expresi�n reservada, y la mirada de sus claros ojos transmite la "
"firmeza y la terquedad propias de su raza.\n");
SetRaceDescription(
"El clan de los Cinturaancha desciende de uno de los Siete Padres de la raza enana "
"que despert� en la parte central de las monta�as Azules, bajo el Monte Dolmed.\n"
"Fundaron el reino enano de Gabilgathol, llamada por los Elfos Belegost, o gran "
"fortaleza, la m�s impresionante de las dos ciudades enanas de las Ered Luin.\n"
"Fueron los guerreros de esta ciudad, ataviados con cotas de anillos inventadas "
"por ellos y de m�scaras de horrenda apariencia que los defend�an del fuego, quienes rodearon "
"al gran drag�n Glaurung, quien fue herido por el se�or enano Azagh�l, a quien mat�.\n"
"Su ciudad se mantuvo hasta el final de la Primera Edad, siendo arruinada por los "
"tumultos y terremotos acaecidos durante la guerra de la c�lera.\n"
"La mayor�a de los supervivientes emigraron a la �ltima gran mansi�n de los enanos en el "
"oeste de la Tierra Media, Kh�zad-D�m, hogar de los Barbiluengos, donde se mezclaron "
"con dicho clan y el de los Barbafuego, tambi�n exiliados.\n"
"Tras la destrucci�n de esta fortaleza por un Balrog, volvieron a ser un clan errante, "
"y desde entonces se los puede encontrar en enclaves propios o en compa��a de otros "
"clanes, especialmente de los m�s numerosos Barbiluengos.\n"
"Pese a todo, nunca han renunciado a su identidad como clan.\n"
"Son m�s joviales y expresivos que otros enanos, grandes comerciantes y soberbios "
"herreros, pues conservan algunos de los secretos de este arte de sus antepasados de la "
"Primera Edad.\n"
"F�sicamente son algo m�s bajos, anchos, rechonchos y achaparrados que el resto de su "
"raza, de piel clara rojiza, pelo y barbas rubias o doradas, que lucen largas con gran "
"orgullo, y ojos verdes o azules.\n"
"Sus artesan�as son siempre hermosas y lujosas y sus ej�rcitos se caracterizan por el "
"aspecto ampuloso e impecable.\n");
}