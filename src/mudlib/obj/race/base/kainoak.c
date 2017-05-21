/*
DESCRIPCION  : un kainoak
FICHERO      : /obj/race/base/kainoak.c
BASADO       : Creado especificamente para este MUD. Son antropomorfos con
               ciertas caracteristicas que los diferencian. Son mas grandes
               que los humanos (aprox 2,30 m) y tienen replicada la parte
               superior del torso, de forma que tienen 4 brazos. Su cultura
               esta basada en la de los esquimales.
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
  SetAlign  (0);    // ni buenos ni malos
  SetMaxFood   (150);  // son seres grandes
  SetMaxDrink  (150);
  SetMaxAlcohol    (100);
  SetWeight (200000);

  SetSize(P_SIZE_LARGE);
  AddHand("mano superior derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("mano superior izquierda", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("mano inferior derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("mano inferior izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus(P_CON,  5);       // son resistentes
  SetStatBonus(P_DEX, -10);       // poco agiles
  SetStatBonus(P_INT, -10);       // no suelen usar magia
  SetStatBonus(P_STR,  5);       // son fuertes
  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(2 * MAX_SUNBRIGHT);
  SetLong(
    "@@Nombre@@ es @@ind@@ kainoak. Su tamaño es algo menor que el de un gigante.\n"
    "El hecho de que tenga 4 brazos identifica claramente a su raza. Parece muy\n"
    "fuerte, aunque quizá algo lent@@suf@@. Su mirada es fija, tanto que cuando te\n"
    "mira sientes un escalofrío, como si se hubiera traído con @@pron@@ el frío de\n"
    "su tierra natal, allá en el helado norte.\n");
  SetRaceDescription (
    "Los kainoak viven en las heladas llamuras del norte. Fisicamente son unos seres\n"
    "seres de apariencia antropomorfa, pero jamas se confundirian con los humanos.\n"
    "Son mas grandes y fuertes que un humano, pero menos que un gigante. Lo que mas\n"
    "llama la atencion de su anatomia es que tienen replicada la parte superior del\n"
    "torso, por lo que tienen 4 brazos. Su piel es palida y suelen tener largas\n"
    "cabelleras. Su condicion fisica los convierte en excelentes guerreros. Luchan\n"
    "cuerpo a cuerpo fieramente y el hecho de disponer de brazos les convierte en\n"
    "dificiles adversarios. En cambio, no son muy buenos con la magia, y por ello no\n"
    "suelen emplearla.\n"
    "Se organizan en grupos tribales gobernados por un pequenyo grupo de lideres.\n"
    "Son seres nomadas que viven en las lejanas llanuras heladas del norte en casas\n"
    "fabricadas con pieles o bloques de hielo.\n");
}
