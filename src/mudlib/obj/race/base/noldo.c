/*
DESCRIPCION  : Elfos Noldor o Altos Elfos, los más poderosos de todos.
FICHERO      : /obj/race/base/noldo.c
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
  SetAlign(50);
  SetBando(P_BANDO_LUZ);

  SetMaxFood(80);
  SetMaxDrink(100);
  SetMaxAlcohol(80);
  SetWeight(90000);
  SetSize(P_SIZE_LARGE);

  AddHand("elegante mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("elegante mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus (P_CON,1);
  SetStatBonus (P_DEX,2);
  SetStatBonus (P_INT,3);
  SetStatBonus (P_STR,1);
  SetStatBonus("Cha", 2);
  SetStatBonus (P_WIS,4);
SetResistance(DT_COLD,20);
SetResistance(DT_GAS,-15);
SetResistance(DT_POISON,10);
SetResistance(DT_PSYCHO,10);
SetResistance(DT_NOAIR,-15);
                  SetResistance(DT_ACID,  -5);
  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(2 * MAX_SUNBRIGHT);
  SetLong(
"@@Nombre@@ es @@ind@@ Elf@@suf@@ Noldo.\n"
"@@Nombre@@ es más alt@@suf@@  que la gran mayoría de los humanos y  elfos de otros "
"linajes, de cuerpo esbelto y bien formado aunque atlético y vigoroso.\n"
"De un negro azabache son sus lisos cabellos, y su rostro, de una marmórea belleza "
"imperecedera que los siglos no tocan ni tocarán, parece irradiar una luz interior "
"que nada podría apagar ni turbar.\n"
"Sus ojos grises, albergan la sabiduría de innumerables años y secretos, y su mirada, "
"aunque grave y orgullosa, transmite cierto sentimiento de nostálgica tristeza.\n"
"En sus movimientos y su apostura, @@Nombre@@ aparece revestid@@suf@@ de un poder, "
"una majestad y una belleza que solo el más grande pueblo de los Elfos que aún "
"camina por las tierras mortales podría tener.\n");
  SetRaceDescription(
  "Los elfos Noldor o Altos Elfos del Oeste son el más escaso y noble de los pueblos "
  "élficos que aún sobreviven en la Tierra Media.\n"
  "Exiliados de Valinor, volvieron a la Tierra Media en la Primera Edad y libraron una "
  "larga y sangrienta guerra contra Morgoth y sus siervos pero finalmente fueron "
  "completamente derrotados, diezmados y sus reinos destruídos del primero al último.\n"
  "A partir de entonces y durante los siguientes seis mil años han ido abandonando la "
  "Tierra Media aunque a finales de la Tercera Edad aún subsisten en algunos "
  "refugios protegidos o ierran bajo las estrellas cantando las glorias de edades pasadas.\n"
  "Raza inmortal como el resto de Elfos, son maestros en las artes de la guerra, la "
  "orfebrería, la construcción y las artesanías de las forjas del metal y maestros del "
  "saber y los más orgullosos, organizados y nobles de los elfos de Endor.\n"
  "Pese a todo ello, sufren una gran nostalgia por el pasado y añoran volver a Valinor,"
  " lo que los hace melancólicos.\n");
}
