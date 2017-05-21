/*
DESCRIPCION  : Un variag, nómadas brutales de Khänd al servicio de Sauron.
FICHERO      : /obj/race/base/variag.c
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

  SetAlign  (-15);
  SetMaxFood   (105);
  SetMaxDrink  (95);
  SetMaxAlcohol    (100);
  SetSize(P_SIZE_LARGE);
  SetBando(P_BANDO_OSCURIDAD);
  SetWeight (80000);
  AddHand   ("oscura mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand   ("oscura mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus   (P_CON, 0);
  SetStatBonus   (P_DEX, 1);
  SetStatBonus   (P_INT, -1);
  SetStatBonus   (P_STR, 1);
  SetStatBonus(P_WIS, -1);
SetStatBonus("Cha", 0);
  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(3 * MAX_SUNBRIGHT);
  SetLong(
"@@Nombre"" pertenece al pueblo de los  Variag, nómadas brutales de la meseta de Khänd.\n"
"Mide sobre el metro setenta y pesará unos ochenta kilos.\n"
"Es @@ind@@ individu@@suf@@ nervud@@suf@@, fornid@@suf@@ y curtid@@suf@@.\n"
"Su piel es de un color gris oscuro casi negro, sus ojos de mirada hosca y despiadada "
"son de color marrón rojizo y su cabello negro, largo y muy liso.\n"
"La expresión de su rostro traiciona un carácter seguro de sí mismo, celoso, impulsivo "
"y temerario.\n");
SetRaceDescription(
"Los Variags son un pueblo semi-nómada, brutal y oscuro que habita en la "
"meseta de Khänd.\n"
"Fuertemente influenciados por Sauron y las continuas guerras entre sí y contra sus "
"vecinos, llevan una vida de brutalidad, pillaje y robos.\n"
"Los guerreros de élite y las sacerdotisas dirigen las distintas bandas, dedicadas al "
"pastoreo además de a la guerra.\n"
"Son soberbios jinetes y fieros guerreros, odian a todas las razas no humanas y "
"desprecian a todos los hombres que no los hayan derrotado recientemente.\n");
}