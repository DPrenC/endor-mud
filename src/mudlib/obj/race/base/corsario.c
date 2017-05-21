/*.
Descripci�n. Corsarios, descendientes de los D�nedain exiliados de gondor durante la "
"Lucha entre Parientes.

FICHERO      : /obj/race/base/corsario.c
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

  SetAlign  (-40);
  SetMaxFood   (100);
  SetMaxDrink  (95);
  SetMaxAlcohol    (105);
  SetSize(P_SIZE_LARGE);

  SetWeight (105000);
  SetBando(P_BANDO_OSCURIDAD);

  AddHand   ("fuerte mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand   ("fuerte mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus   (P_CON, 2);
  SetStatBonus   (P_DEX, 1);
  SetStatBonus   (P_INT, 0);
  SetStatBonus   (P_STR, 1);
    SetStatBonus("Cha", 1);
      SetStatBonus(P_WIS, 1);

  SetResistance(DT_POISON, 100);
  SetResistance(DT_GAS, 100);
  SetResistance(MT_GAS, 100);
  SetResistance(DT_NOAIR, 100);
  SetResistance(MT_NOAIR, 100);
  SetResistance(DT_FIRE, 100);
  SetResistance(MT_FIRE, 100);
  SetResistance(DT_PSYCHO, 100);
  SetResistance(MT_PSYCHO, 100);
  SetResistance(DT_PIERCE, 100);
  SetResistance(MT_PIERCE, 100);
  SetResistance(DT_SLASH,  100);
  SetResistance(MT_SLASH,  100);
    SetResistance(MT_WATER, 100);
      SetResistance(DT_WATER,  100);
        SetResistance(MT_BLUDGEON,  100);
          SetResistance(DT_BLUDGEON,  100);
            SetResistance(MT_ELECTRO,  100);
              SetResistance(DT_ELECTRO,  100);
                SetResistance(MT_ACID,  100);
                  SetResistance(DT_ACID,  100);


  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(3 * MAX_SUNBRIGHT);
  SetLong(
  "@@Nombre@@ es @@ind@@ Corsari@@suf@@, descendiente de los D�nedain rebeldes de Gondor.\n"
  "@@Nombre@@ es alt@@suf@@, fuerte y de noble apostura y su piel es clara, ligeramente atezada por el c�lido clima costero.\n"
  "Sus cabellos de color casta�o muy oscuro enmarcan un rostro de facciones regulares, "
  "desvirtuadas por una perpetua expresi�n desde�osa y altiva, acentuada por la mirada "
  "orgullosa y dura de sus acerados ojos grises.\n");
  SetRaceDescription(
  "Los Corsarios de Umbar descienden de los rebeldes D�nedain que se alzaron en armas en "
  "Gondor en el a�o 1432 de la Tercera Edad cuando el heredero al trono se cas� con una "
  "princesa de los Hombres del Norte, pues jam�s nadie de la Casa Real se hab�a casado "
  "con alguien de una raza menor, y pensaban que ello malograr�a la majestad y poder de los Reyes.\n"
  "Tras quince a�os de guerra que desangr� el reino y lo hicieron declinar a �l y a la "
  "raza de los D�nedain, los rebeldes fueron derrotados y dirigidos por sus capitanes "
  "que se dec�an reyes, tomaron la flota de gondor y huyeron a Umbar, donde se "
  "establecieron e  hicieron fuertes.\n"
  "Desde entonces, han sostenido luchas con los m�s numerosos Haradrim y N�men�reanos "
  "Negros por el poder, aunque todos ellos se unen cuando se trata de atacar a Gondor.\n"
  "Los Corsarios han vuelto a la cultura marinera de la antigua N�menor y sus mayores "
  "ambiciones son mantener pura su estirpe sin mezclarse con hombres menores y atacar "
  "por mar a Gondor, de donde se consideran exiliados y a la cual pretenden reconquistar.\n"
  "Sus feroces ataques desde el mar son temidos por las gentes de las costas de Gondor, "
  "y su pericia en la costrucci�n y manejo de barcos ha llegado a equipararse a la "
  "pose�da por los antiguos N�men�reanos.\n");
  }