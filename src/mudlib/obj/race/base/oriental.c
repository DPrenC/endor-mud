/*
DESCRIPCION  : Un oriental, nómadas en su mayoría aliados de Sauron.
FICHERO      : /obj/race/base/oriental.c
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
  SetMaxDrink  (100);
  SetMaxAlcohol    (100);
  SetSize(P_SIZE_LARGE);
  SetBando(P_BANDO_OSCURIDAD);
  SetWeight (75000);
  AddHand   ("mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand   ("mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus   (P_CON, 0);
  SetStatBonus   (P_DEX, 1);
  SetStatBonus   (P_INT, 0);
  SetStatBonus   (P_STR, 0);
  SetStatBonus(P_WIS, -1);
SetStatBonus("Cha", 0);
  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(3 * MAX_SUNBRIGHT);
  SetLong(
"@@Nombre@@ es @@ind@@ Oriental de las estepas de Rhün.\n"
"Es @@ind@@ individu@@suf@@ de cuerpo compacto pero ágil y fibroso, midiendo sobre un metro "
"sesenta y cinco y pesando unos setenta kilos.\n"
"Tiene cabello moreno y piel atezada, de un tono amarillento.\n"
"Su rostro de facciones duras tiene una expresión decidida y valerosa, y sus fríos ojos "
"oscuros denuncian un corazón valeroso y temerario.\n"
"@@Nombre@@ da en su conjunto impresión de dureza, voluntad férrea y ardor "
"guerrero tan típicos en los Orientales.\n");
SetRaceDescription(
"Los Orientales son un grupo muy amplio de pueblos que habitan en las inmensas estepas "
"y llanuras que se extienden al este de Rhovanion, el mar de Rhün y Mordor.\n"
"Divididos en un sin número de tribus, confederaciones y grupos nómadas, llevan una "
"vida centrada en la cría de ganado y caballos, trasladando sus móviles campamentos "
"de un lugar a otro mediante grandes carromatos, en busca de mejores pastos.\n"
"Esta actividad se ve completada por la práctica del comercio con otras tribus de "
"orientales y otras culturas, y mediante la guerra y el pillaje.\n"
"Los Orientales son hábiles jinetes y el combate a caballo es para ellos un arte.\n"
"Como señal de distinción, sus caudillos y guerreros más notables luchan en rápidos y "
"mortíferos carros de guerra.\n"
"A lo largo de la historia, uno u otro de estos pueblos ha acrecentado su poder "
"e influencia hasta someter a muchas otras tribus e invadido las tierras del Oeste, "
"como fue el caso de los Balchoth o los Aurigas.\n"
"Fuertemente influenciados por Sauron y sus emisarios, en su mayoría odian a Gondor, "
"los Dúnedain y a todos los hombres descendientes de los Hombres del Norte, como "
"los Rohirrim.\n"
"Sus artesanías son buenas y particulares, sobretodo en el trabajo del cuero y la piel, "
"y tienen los suficientes conocimientos sobre  forja como para ir más o menos bien "
"equipados, aunque esto depende en gran medida del grupo.\n"
"Algunos de ellos, se benefician en este aspecto del comercio con los enanos de los "
"clanes que habitan en las Orocarni o Montañas Rojas, en la zona más oriental de Rhün.\n");
}