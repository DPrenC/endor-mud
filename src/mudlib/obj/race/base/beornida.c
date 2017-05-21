/*
DESCRIPCION  : Un beórnida u Hombre-oso. Humanos enormes en relación con la naturaleza, independientes y feroces pero buenos,
vegetarianos, algunos se convierten en oso.
FICHERO      : /obj/race/base/beornida.c
BASADO       : /obj/race/base/human.c de NightFall
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

  SetAlign  (0);
  SetMaxFood   (125);
  SetMaxDrink  (110);
  SetMaxAlcohol    (150);
  SetSize(P_SIZE_LARGE);

  SetWeight (120000);
  SetBando(P_BANDO_LUZ);
  AddHand   ("manaza derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand   ("belluda manaza izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus   (P_CON,2);
  SetStatBonus   (P_DEX,-2);
  SetStatBonus   (P_INT,-1);
  SetStatBonus   (P_STR,3);
    SetStatBonus("Cha", 1);
      SetStatBonus(P_WIS, -1);
  SetResistance(DT_FIRE,-10);
  SetResistance(DT_COLD,15);
  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(3 * MAX_SUNBRIGHT);
  SetLong(
  "@@Nombre@@ es @@ind@@ Beórnida, perteneciente a un antiguo clan de hombres del Norte.\n"
  "@@Nombre@@ mide alrededor de los dos metros y debe de pesar unos ciento veinte kilos.\n"
  "Es @@ind@@ individu@@suf@@ de constitución hercúlea, con poderosa estructura ósea.\n"
  "Su piel es clara, su rostro afable, de expresión amistosa, y sus ojos, de un verde "
  "profundo, irradian camaradería y jovialidad, aunque la gran envergadura que exhibe "
  "no recomienda arriesgarse a incurrir en su tormentosa ira.\n"
  "@@Nombre@@ es pelirroj@@suf@@, luciendo una larga y desgreñada melena que cae cual "
  "ígnea cascada sobre sus hombros y espalda.\n");

  SetRaceDescription("\
  Los Beórnidas son un clan de Hombres del Norte que habitan los  valles del Alto "
  "Anduin entre el Bosque Negro y las Montañas Nubladas y que mantienen abiertos los "
  "pasos montañosos y el Vado de la Carroca que permite las comunicaciones entre "
  "Eriador y las Tierras del Este, cobrando altos peajes a los viajeros de bien que "
  "cruzan su territorio.\n"
  "Son hombres enormes, de gran altura y fortaleza, muy belludos y de piel clara, "
  "cabellos rojizos y ojos azules o verdes.\n"
  "Son gentes reservadas aunque alegres y joviales cuando están en compañía de amigos, "
  "pero su cólera cuando despierta es temible.\n"
  "Viven en pequeñas unidades familiares o clanes en torno a granjas y pequeños enclaves "
  "donde cultivan, crían ganado y producen miel, su alimento favorito.\n"
  "Algunos de ellos, como Beorn, el caudillo que les dió nombre, son capaces de "
  "transformarse en oso y comunicarse con los animales, formando una hermandad secreta "
  "encargada de defender a su pueblo y su tierra, son los llamados Multiformes.\n"
  "El resto del pueblo está constituído por buenos guerreros, bárbaros y excelentes "
  "rastreadores.\n");
  }