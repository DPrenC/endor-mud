/*
DESCRIPCION  : Un dúnedain, o Altos Hombres, Hombres de Gondor, y Arnor. Una especie
de humanos superiores.
FICHERO      : /obj/race/base/alto-hombre.c

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

  SetAlign  (40);
  SetMaxFood   (100);
  SetMaxDrink  (100);
  SetMaxAlcohol    (105);
  SetSize(P_SIZE_LARGE);

  SetWeight (105000);
  SetBando(P_BANDO_LUZ);

  AddHand   ("fuerte mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand   ("fuerte mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus   (P_CON, 2);
  SetStatBonus   (P_DEX, 0);
  SetStatBonus   (P_INT, 1);
  SetStatBonus   (P_STR, 1);
    //SetStatBonus   (P_CAR, 1);
      //SetStatBonus   (P_SAB, 1);
  SetResistance(DT_FIRE,5);
SetResistance(DT_COLD,5);
SetResistance(DT_POISON,5);
SetResistance(DT_PSYCHO,3);
                  SetResistance(DT_ACID,  1);
  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(3 * MAX_SUNBRIGHT);
  SetLong(
  "@@Nombre es @@ind@@ Dúnadan, descendietes de los antiguos númenóreanos.\n"
  "Es muy alt@@suf@@, mucho más que los hombres comunes, y su cuerpo es fuerte y bien "
  "proporcionado.\n"
  "Su piel es clara y negro como azabache es su pelo, que lleva largo sobre los "
  "hombros.\n"
  "El rostro de @@Nombre@@ es hermoso, de facciones regulares y nariz aquilina, y sus "
  "ojos, del más acerado gris, tienen una mirada grave y solemne.\n"
  "Como miembro del antiguo pueblo de los Dúnedain, @@Nombre@@ da en su conjunto una "
  "impresión de majestad, fuerza y sabiduría.\n");

  SetRaceDescription(
  "Los Altos Hombres descienden de los Edain que se establecieron en la isla de Númenor "
  "en la Segunda Edad. Su fe en Eru, los Valar y la ayuda prestada a los Elfos en las "
  "antiguas Guerras de la Primera Edad, han bendecido a esta raza con numerosos dones, "
  "que, pese a haber comenzado a desaparecer antes incluso del hundimiento de Númenor y "
  "haber continuado su declive hasta la actualidad, perduran aún en cierto grado y los "
  "hacen distintos y superiores al resto de Hombres.\n"
  "Son muy altos, entre el metro noventa y los dos metros, de gran resistencia y "
  "fortaleza, poderosa musculatura y contundente estructura ósea que los hace "
  "físicamente impresionantes y pese a todo ello, no carecen de atractivo y elegancia, "
  "siendo estos mayores que los del resto de Hombres.\n"
  "Tienen piel clara, escepto los que por largo tiempo han habitado en regiones más "
  "cálidas y tienen un cierto color atezado, de cabellos castaño oscuro o negro azabache "
  "y ojos grises, azulados o negros.\n"
  "Sus sociedades están altamente organizadas y la dilatada longevidad de la que aún hoy "
  "disfrutan, los hacen erigirse a menudo en mentores y conquistadores de los hombres "
  "comunes, lo que ha desencadenado a menudo toda clase de odios y resquemores.\n"
  "Son excelentes guerreros, arquitectos, constructores, marineros, curanderos y "
  "eruditos, y sobretodo en el caso de los Dúnedain, transmiten cierto aire élfico.\n"
  "Actualmente, existen tres civilizaciones de Altos hombres: "
  	"los Dúnedain del Norte y de Gondor, los Númenóreanos Negros y los Corsarios.\n");
  	}