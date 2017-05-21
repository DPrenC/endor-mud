/*
DESCRIPCION  : Un hombre de los bosques, habitantes del Bosque Negro.
FICHERO      : /obj/race/base/hombre-bosque.c
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

  SetAlign  (20);
  SetMaxFood   (95);
  SetMaxDrink  (105);
  SetMaxAlcohol    (100);
  SetSize(P_SIZE_LARGE);
  SetBando(P_BANDO_LUZ);
  SetWeight (90000);
  AddHand   ("diestra mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand   ("diestra mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus   (P_CON, 0);
  SetStatBonus   (P_DEX, 1);
  SetStatBonus   (P_INT, 0);
  SetStatBonus   (P_STR, 0);
        SetStatBonus   ("Cha", 0);
      SetStatBonus   (P_WIS, -1);

  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(3 * MAX_SUNBRIGHT);
  SetLong(
"@@Nombre@@ pertenece al pueblo de los Hombres del Bosque.\n"
"Es alt@@suf@@, de constitución normal pero fibrosa, midiendo alrededor del metro "
"ochenta y pesando cerca de los noventa kilos.\n"
"Su piel es clara, con un leve tono cobrizo y el rubio de sus cabellos así como  el "
"azul de sus ojos de mirada reservada denotan sus orígenes nórdicos.\n"
"Los rasgos de @@Nombre@@ son angulosos, marcados y tanto la expresión de su rostro "
"como sus movimientos denotan que es alguien poco acostumbrado al contacto humano y muy "
"apto para coexistir con la naturaleza en las tierras salvajes.\n");

SetRaceDescription(
"Los hombres del bosque, descienden de los antiguos nórdicos de Rhovanion y están "
"emparentados con los beórnidas y los rohirrim entre otros grupos.\n"
"Son un pueblo esquivo, que se relaciona poco con los forasteros a parte de  sus vecinos "
"elfos silvanos y beórnidas, que viven en pequeños clanes, familias o tribus errantes "
"que se desplazan por la parte media del Bosque Negro cazando y recolectando.\n"
"Habitan en cabañas al pie de los árboles pero sobretodo en plataformas situadas en las "
"copas de los mismos, construyendo verdaderos poblados en las altas ramas para "
"defenderse de las criaturs malignas que pueblan el bosque.\n"
"Son unos cazadores, rastreadores y exploradores excelentes, conocen el uso de muchas "
"plantas medicinales y su artesanía aunque rústica tiene cierto grado de hermosura.\n");
}