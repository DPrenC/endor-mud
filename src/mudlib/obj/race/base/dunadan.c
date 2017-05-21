/*
DESCRIPCION  : Un d�nedain, o Altos Hombres, Hombres de Gondor, y Arnor. Una especie
de humanos superiores.
FICHERO      : /obj/race/base/dunadan.c
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
    SetStatBonus("Cha", 1);
      SetStatBonus(P_WIS, 1);
  SetResistance(DT_FIRE,5);
SetResistance(DT_COLD,5);
SetResistance(DT_POISON,5);
SetResistance(DT_PSYCHO,3);
                  SetResistance(DT_ACID,  1);
  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(3 * MAX_SUNBRIGHT);
  SetLong(
  "@@Nombre@@ es @@ind@@ D�nadan, descendiente de los antiguos n�men�reanos de Oesternesse.\n"
  "Es muy alt@@suf@@, mucho m�s que los hombres comunes, y su cuerpo es fuerte y bien "
  "proporcionado.\n"
  "Su piel es clara y negro como azabache es su pelo, que lleva largo sobre los "
  "hombros.\n"
  "El rostro de @@Nombre@@ es hermoso, de facciones regulares y nariz aquilina, y sus "
  "ojos, del m�s acerado gris, tienen una mirada grave y solemne.\n"
  "Como miembro del antiguo pueblo de los D�nedain, @@Nombre@@ da en su conjunto una "
  "impresi�n de majestad, fuerza y sabidur�a, as� como un cierto aire de intemporalidad "
  "�lfica.\n");

  SetRaceDescription(
  "Los �ltimos se�ores de los Fieles, los N�men�reanos que manten�an el respeto a los "
  "Valar y la amistad con los Elfos a fines de la Segunda Edad, condujeron una flota de "
  "nueve barcos a la Tierra Media y fundaron dos reinos en el Exilio: Arnor en el Norte "
  "y Gondor en el Sur.\n"
  "Con el tiempo el reino de Arnor se dibidi� y fue destru�do y los pocos "
  "supervivientes conducidos por los descendientes de Elendil conocidos como los "
  "Montaraces, pasaron a la sombra y a fines de la Tercera Edad pocos sab�an quienes eran.\n"
  "En el Sur el reino de Gondor vivi� gran esplendor pero a finales de la Tercera Edad "
  "ha quedado muy reducido y su estirpe real se ha extinguido, siendo gobernado por los "
  "Senescales y levant�ndose como principal basti�n contra Mordor y sus incontables "
  "aliados.\n"
  "Los D�nedain son una raza de hombres altos y robustos, de apostura y rostro noble y "
  "apariencia majestuosa, cabellos habitualmente oscuros y ojos grises, que guardan un "
  "vago parecido con los Elfos.\n"
  "Son la raza m�s encumbrada de todos los Hombres, una raza orgullosa, a�n en su "
  "declive longeva, dotados de poderes y habilidades fuera del alcance de otros "
  "mortales, maestros de las artes, las ciencias y la guerra, y aunque menguados en "
  "n�mero y poder, son el principal obst�culo que se interpone entre Sauron y la "
  "conquista total de la Tierra Media.\n"
);
}

