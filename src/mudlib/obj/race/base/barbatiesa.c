/*
DESCRIPCION  : un enano Barbatiesa, del norte de las montañas Orocarni en el lejano 
oriente.
FICHERO      : /obj/race/base/barbatiesa.c
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
  SetMaxAlcohol(205);
  SetWeight(73000);
  SetSize(P_SIZE_MEDIUM);
  SetBando(P_BANDO_NEUTRO);
  AddHand("callosa mano derecha", 0, WEAPON_CLASS_OF_HANDS*2);
  AddHand("callosa mano izquierda", 0, WEAPON_CLASS_OF_HANDS*2);

  SetStatBonus(P_CON,3);
  SetStatBonus(P_DEX,-3);
  SetStatBonus(P_INT,-1);
  SetStatBonus(P_STR,2);
  SetStatBonus(P_WIS, 0);
SetStatBonus("Cha", -1);
  SetResistance(DT_FIRE,18);
SetResistance(DT_COLD,12);
SetResistance(DT_GAS,5);
SetResistance(DT_POISON,10);
SetResistance(DT_PSYCHO,40);
SetResistance(DT_NOAIR,5);
SetResistance(DT_WATER,-35);
SetResistance(MT_WATER,-25);
                  SetResistance(DT_ACID,  5);
  SetIVision(-REL_STATE(ND_PRENOON, MAX_SUNBRIGHT));
  SetUVision(MAX_SUNBRIGHT);

  SetLong(
  "@@Nombre@@ es @@ind@@ enan@@suf@@ del clan de los Barbatiesa.\n"
  "Como todos los enanos, es baj@@suf@@, robust@@suf@@, de grandes manos y pies"
  "y facciones anchas y marcadas.\n"
  "@@Nombre@@ es ligeramente más alt@@suf@@ de lo  normal entre esta raza, y su "
  "cabello castaño es largo, desgreñado y permanentemente alborotado, detalle que da "
  "nombre al clan del que procede.\n"
  "Su greñuda melena enmarca un rostro en cierto grado inexpresivo aunque feroz, de "
  "piel cetrina y áspera, y ojos algo más pequeños de lo común, que fulguran bajo el "
  "amplio entrecejo.\n"
  "La nariz es bulbosa y amplia su boca, y la mirada algo desenfocada de sus pupilas "
  "denota su caracter tornadizo e inestable.\n");
  SetRaceDescription(
  "El clan de los Barbatiesa desciende de uno de los Grandes Padres que despertó en "
  "el norte de las Orocarni o montañas Rojas.\n"
  "Poco conocidos en las tierras del Oeste, físicamente son algo más altos que el resto "
  "de los enanos y ligeramente más esbeltos.\n"
  "Viven en el norte de las Orocarni, y son famosos por su mal talante, falta de "
  "disciplina y, para ser enanos, poca habilidad en las artes de la forja, la "
  "minería y la cantería.\n"
  "Sus minas y refugios son toscos aunque efectivos, y aunque mal equipados, son "
  "guerreros feroces y sanguinarios, valerosos hasta la temeridad.\n"
  "Se dividen en grupos dirigidos por los individuos más fuertes, que ierran por sus "
  "territorios o guerrean en otras tierras, pues aman el combate y la "
  "exhibición de la fuerza física por encima de todo.\n"
  "Pese a haber sido sobornados por Sauron en ciertas ocasiones para luchar a su "
  "servicio, siempre lo han hecho de forma voluntaria, pues su tozudez es tan "
  "inquebrantable como la del resto de su raza.\n"
  "En cualquier caso, siempre se han mantenido fieles a los demás clanes, puesto que "
  "la raza enana se considera en conjunto un gran y abigarrado clan, siempre en "
  "contacto entre sus siete divisiones.\n"
  "Suelen lucir melenas y barbas largas y caóticamente erizadas, lo que ha dado "
  "nombre al clan.\n");
}