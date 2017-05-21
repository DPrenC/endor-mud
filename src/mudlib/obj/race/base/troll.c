/*
DESCRIPCION  : un troll
FICHERO      : /obj/race/base/troll.c
BASADO       : /obj/race/base/troll.c [randyandy@nightfall]
--------------------------------------------------------------------------------
*/

#include <combat.h>
#include <config.h>
#include <attributes.h>
#include <nightday.h>
#include <properties.h>
inherit "/obj/raceobj";

create_blueprint(){
  ::create_blueprint();

  SetAlign  (-10);
  SetMaxFood   (100);
  SetMaxDrink  (100);
  SetMaxAlcohol    (200);
  SetWeight (90000);
  SetSize(P_SIZE_LARGE);

  AddHand("garra derecha", 0, WEAPON_CLASS_OF_HANDS*2);
  AddHand("garra izquierda", 0, WEAPON_CLASS_OF_HANDS*2);

  SetStatBonus(P_CON,  3);
  SetStatBonus(P_DEX, -1);
  SetStatBonus(P_INT, -6);
  SetStatBonus(P_STR,  4);
  SetIVision(-(MAX_SUNBRIGHT));
  SetUVision(MAX_SUNBRIGHT);
  SetLong(
    "@@Nombre@@ es @@ind@@ troll. Sus ojos brillan y su cuerpo parece peligroso.\n"
    "Un par de largos colmillos sobresalen de su boca y un largo y oscuro\n"
    "pelaje recorre todo su cuerpo. No parece muy inteligente, pero sí muy fuerte y\n"
    "resistente.\n");
  SetRaceDescription (
    "Los trolls son seres grandes y fuertes. Una largo pelaje oscuro recorre todo su\n"
    "su cuerpo. No son muy inteligentes, pero lo compensan con una gran fuerza\n"
    "fisica y una paciencia y tenacidad innatas, asi que tarde o temprano consiguen\n"
    "sus objetivos.\n"
    "Su condicion fisica los convierte en excelentes guerreros. Luchan cuerpo a\n"
    "cuerpo fieramente y de una forma desorganizada e imprevisible, lo cual hace sus\n"
    "emboscadas muy peligrosas. Ver perfectamente en la oscuridad y aunque son\n"
    "capaces de moverse a plena luz del dia, sus facultades se ver mermadas.\n"
    "Son bastante anarquicos por lo que no poseen una estructura social compleja. Se\n"
    "organizan en grupos tribales gobernados por algun caudillo. Viven en cuevas o\n"
    "desfiladeros y suelen salir de alli en busca de viajeros o caravanas que\n"
    "asaltar. Se sabe que en ocasiones se han aliado temporalmente con orcos o con\n"
    "gigantes.\n"
    "Son negados para la magia o incluso para el uso de objetos magicos.\n");
}
