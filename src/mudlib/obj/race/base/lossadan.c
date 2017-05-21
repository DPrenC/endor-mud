/*
DESCRIPCION  : Lossadan,hombre de las nieves que habitanen las gélidastierras al 
norte de Eriador.
FICHERO      : /obj/race/base/lossadan.c
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

  SetAlign  (10);
  SetMaxFood   (105);
  SetMaxDrink  (95);
  SetMaxAlcohol    (95);
  SetSize(P_SIZE_LARGE);
  SetBando(P_BANDO_NEUTRO);
  SetWeight (75000);
  AddHand   ("mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand   ("mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus   (P_CON, 1);
  SetStatBonus   (P_DEX, 1);
  SetStatBonus   (P_INT, 0);
  SetStatBonus   (P_STR, 0);
  SetStatBonus(P_WIS, -1);
SetStatBonus("Cha", 0);
SetResistance(DT_COLD,20);
  SetResistance(DT_FIRE, -20);


  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(3 * MAX_SUNBRIGHT);
  SetLong(
  "@@Nombre@@ es @@ind@@ Lossadan, perteneciente al pueblo de los hombres de las nieves.\n"
  "Mide sobre el metro setenta y pesa unos ochenta kilos, siendo de constitución "
  "rechoncha, con destacada musculatura y pies y manos grandes.\n"
  "Su amplio rostro de anchas facciones de expresión reservada, está enmarcado por "
  "cabello rubio, y en sus ojos azul claro anida una mirada tranquila, aunque determinada.\n");
  SetRaceDescription(
  "Los Lossoth u hombres de las nieves habitan en lasheladas y extensas tierras "
  "situadas al norte de Eriador.\n"
  "Su cultura primitiva de cazadores, pescadores y recolectores se centra en las "
  "migraciones de los animales de los que subsisten, trasladando los campamentos de sus "
  "pequeños clanes o grandes familias entre la costa y los fríos páramos y bosques del interior.\n"
  "No utilizan el hierro y los pocos metales que conocen son toscamente trabajados, pues "
  "los materiales más extendidos son la piel, el cuero, el pedernal y el hueso.\n");
}