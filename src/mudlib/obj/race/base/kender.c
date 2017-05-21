/*
DESCRIPCION  : un kender
FICHERO      : /obj/race/base/kender.c
BASADO       : /obj/race/base/halfling.c [randyandy@nightfall] [cadra@nightfall]
--------------------------------------------------------------------------------
*/

#include <combat.h>
#include <config.h>
#include <attributes.h>
#include <nightday.h>
#include <properties.h>
inherit "/obj/raceobj";

create_blueprint()
{
  ::create_blueprint();
  SetAlign(50);
  SetMaxFood(75);
  SetMaxDrink(75);
  SetMaxAlcohol(50);
  SetSize(P_SIZE_SMALL);

  SetWeight(40000);
  AddHand("mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus(P_CON,1);
  SetStatBonus(P_DEX,3);
  SetStatBonus(P_INT,-1);
  SetStatBonus(P_STR,-3);
  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(2 * MAX_SUNBRIGHT);
  SetLong(
"@@Nombre@@ es @@ind@@ kender. Su apariencia tiene un cierto parecido con la de\n\
un elfo, pero apenas supera el metro y medio de estatura. Tiene una larga melena\n\
de color ocre recogida en una trenza. Es bastante curios@@suf@@ y no para de\n\
moverse de un lado para otro examinándolo todo, en especial tu inventario...\n\
Ese brillo en sus pequeños ojillos azules no te inspira demasiada confianza.\n");
  SetRaceDescription(
"Los kender son unos seres de mediana estatura y con un cierto parecido con los\n"
"elfos. Su pelo es de tonos ocres y suelen dejarselo crecer en una larga melena.\n"
"Fisicamente son habiles y bastante agiles pese a su poca estatura. Son seres\n"
"sensibles, risuenyos y muy expresivos. Su extrema curiosidad les hace ser mas\n"
"bien temerarios y es la causa de que tiendan a apropiarse de objetos que les son\n"
"ajenos. Segun ellos se trata de inocentes apropiaciones y no desde luego no de\n"
"robos. Su forma de ser hace que tengan la especial habilidad para incordiar y\n"
"poner a prueba los nervios de aquellos que tienen alrededor. No estan\n"
"especialmente dotados para la magia y por ello no suelen emplearla.\n");

}
