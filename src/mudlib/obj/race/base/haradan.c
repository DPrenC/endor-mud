
/*
DESCRIPCION  : Un haradan, hombre de Harad, grandes tierras desérticas al sur de Gondor.
FICHERO      : /obj/race/base/haradan.c
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
  SetMaxFood   (100);
  SetMaxDrink  (80);
  SetMaxAlcohol    (95);
  SetSize(P_SIZE_LARGE);
  SetBando(P_BANDO_OSCURIDAD);
  SetWeight (65000);
  AddHand   ("morena mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand   ("morena mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus   (P_CON, 0);
  SetStatBonus   (P_DEX, 1);
  SetStatBonus   (P_INT, -1);
  SetStatBonus   (P_STR, 0);
      SetStatBonus   ("Cha", 0);
      SetStatBonus   (P_WIS, -2);
  SetResistance(DT_FIRE,-15);
SetResistance(DT_COLD,-15);
SetResistance(DT_PSYCHO,-3);

  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(3 * MAX_SUNBRIGHT);
  SetLong(
"@@Nombre@@ es @@ind@@ Haradan, proveniente de las desérticas tierras del Sur.\n"
"@@Nombre@@ es de estatura media y complexión nervuda y curtida, rondando el metro "
"setenta de altura y pesando unos sesenta y cinco kilos.\n"
"Su piel es de un tono marrón oscuro, tostada por el fiero sol de Harad, sus cabellos "
"muy negros y lisos, y su rostro de expresión cruel y salvaje.\n"
"La mirada de los ojos marrón oscuro de @@Nombre@@ es orgullosa, ardiente y retadora.\n");
SetRaceDescription(
"Los Haradrim o sureños ocupan las tierras al sur de Gondor y Mordor, una enorme "
"extensión de territorios desérticos, semidesérticos y esteparios con poca agua y "
"vegetación escasa, donde las temperaturas son extremadamente altas y difíciles las "
"condiciones de vida.\n"
"La mayoría de la población vive en las costas, estuarios, bahías y orillas de los "
"cursos fluviales, habitando en gran número en la ciudad y puerto de Umbar, aunque la "
"gran mayoría se divide en tribus nómadas o seminómadas que hierran por el territorio.\n"
"Los Haradrim son orgullosos, audaces guerreros y grandes jinetes, combativos e "
"indómitos, luchando a menudo entre sí y contra los Corsarios y Númenóreanos Negros "
"que los han dominado y esclavizado en muchas ocasiones, aunque odian con gran pasión a "
"Gondor y a sus aliados por influencia directa de Sauron, quien los ha azuzado para "
"que invadieran este reino en innumerables ocasiones.\n"
"Su sociedad es fuertemente patriarcal, y sus principales actividades son la guerra, el "
"comercio, el pastoreo y la caza, dedicándose cada grupo a todas estas actividades en "
"distintos grados.\n");
}