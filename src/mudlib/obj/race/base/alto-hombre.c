/*
DESCRIPCION  : Un d�nedain, o Altos Hombres, Hombres de Gondor, y Arnor. Una especie
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
  "@@Nombre es @@ind@@ D�nadan, descendietes de los antiguos n�men�reanos.\n"
  "Es muy alt@@suf@@, mucho m�s que los hombres comunes, y su cuerpo es fuerte y bien "
  "proporcionado.\n"
  "Su piel es clara y negro como azabache es su pelo, que lleva largo sobre los "
  "hombros.\n"
  "El rostro de @@Nombre@@ es hermoso, de facciones regulares y nariz aquilina, y sus "
  "ojos, del m�s acerado gris, tienen una mirada grave y solemne.\n"
  "Como miembro del antiguo pueblo de los D�nedain, @@Nombre@@ da en su conjunto una "
  "impresi�n de majestad, fuerza y sabidur�a.\n");

  SetRaceDescription(
  "Los Altos Hombres descienden de los Edain que se establecieron en la isla de N�menor "
  "en la Segunda Edad. Su fe en Eru, los Valar y la ayuda prestada a los Elfos en las "
  "antiguas Guerras de la Primera Edad, han bendecido a esta raza con numerosos dones, "
  "que, pese a haber comenzado a desaparecer antes incluso del hundimiento de N�menor y "
  "haber continuado su declive hasta la actualidad, perduran a�n en cierto grado y los "
  "hacen distintos y superiores al resto de Hombres.\n"
  "Son muy altos, entre el metro noventa y los dos metros, de gran resistencia y "
  "fortaleza, poderosa musculatura y contundente estructura �sea que los hace "
  "f�sicamente impresionantes y pese a todo ello, no carecen de atractivo y elegancia, "
  "siendo estos mayores que los del resto de Hombres.\n"
  "Tienen piel clara, escepto los que por largo tiempo han habitado en regiones m�s "
  "c�lidas y tienen un cierto color atezado, de cabellos casta�o oscuro o negro azabache "
  "y ojos grises, azulados o negros.\n"
  "Sus sociedades est�n altamente organizadas y la dilatada longevidad de la que a�n hoy "
  "disfrutan, los hacen erigirse a menudo en mentores y conquistadores de los hombres "
  "comunes, lo que ha desencadenado a menudo toda clase de odios y resquemores.\n"
  "Son excelentes guerreros, arquitectos, constructores, marineros, curanderos y "
  "eruditos, y sobretodo en el caso de los D�nedain, transmiten cierto aire �lfico.\n"
  "Actualmente, existen tres civilizaciones de Altos hombres: "
  	"los D�nedain del Norte y de Gondor, los N�men�reanos Negros y los Corsarios.\n");
  	}