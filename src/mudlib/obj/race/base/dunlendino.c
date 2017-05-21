/*
DESCRIPCION  : Un dunlendino, montañeses de las tierras al Oeste de Rohan.
FICHERO      : /obj/race/base/dunlendino.c
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

  SetAlign  (-5);
  SetMaxFood   (100);
  SetMaxDrink  (100);
  SetMaxAlcohol    (105);
  SetSize(P_SIZE_LARGE);
  SetBando(P_BANDO_NEUTRO);
  SetWeight (84000);
  AddHand   ("ruda mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand   ("ruda mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus   (P_CON, 0);
  SetStatBonus   (P_DEX, 0);
  SetStatBonus   (P_INT, 0);
  SetStatBonus   (P_STR, 0);
      SetStatBonus("Cha", 1);
      SetStatBonus(P_WIS, -1);

  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(3 * MAX_SUNBRIGHT);
  SetResistance(DT_COLD,5);
  SetLong(
  "@@Nombre@@ es @@ind@@ Dunlendin@@suf@@.\n"
  "Mide alrededor de un metro setenta y cinco y es de complexión algo rechoncha y robusta,"
  " pesando algo más de los ochenta kilos.\n"
  "@@Nombre@@ es de piel morena y cabellos lisos de color castaño.\n"
  "Su apariencia y modos son algo toscos, su rostro amplio y jovial, aunque en sus ojos "
  "oscuros percibes que es @@ind@@ individu@@suf@@ desconfiad@@suf@@ y poco "
  "comunicativ@@suf@@ con los desconocidos.\n");
  SetRaceDescription(
  "Los Dunlendinos o montañeses son los restos de un antiguo pueblo que antaño habitó a "
  "lo largo de toda la cordillera de las Montañas Blancas, de donde actualmente han desaparecido.\n"
  "Los hombres de los Senderos de los Muertos pertenecían a esta estirpe.\n"
  "Actualmente viven en las colinas, valles y laderas montañosas al oeste de Rohan, "
  "habiendo dado origen algunos de ellos a los actuales hombres de Bree.\n"
  "Muchos son granjeros y ganaderos, aunque  otros continúan viviendo en clanes y "
  "familias como cazadores y recolectores en las montañas Nubladas.\n"
  "Son fieros e independientes guerreros, perpetuamente enemistados con los Rohirrim y "
  "los woses, no gustan de los Dúnedain y muchos desprecian a los Enanos.\n"
  "Últimamente, Saruman ha aprovechado estos odios para armarlos y azuzarlos contra Rohan "
  "e interrumpir las comunicaciones con Eriador.\n");
  }