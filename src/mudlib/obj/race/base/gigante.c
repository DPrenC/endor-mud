/*
DESCRIPCION  : un gigante
FICHERO      : /obj/race/base/gigante.c
BASADO       : /obj/race/base/giant.c [killroy@nightfall] [mateese@nightfall]
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
  SetAlign  (-300);
  SetMaxFood   (500);
  SetMaxDrink  (300);
  SetMaxAlcohol    (1100);
  SetWeight (280000);

  SetSize(P_SIZE_LARGE);
  AddHand("mano derecha", 0, WEAPON_CLASS_OF_HANDS*2);
  AddHand("mano izquierda", 0, WEAPON_CLASS_OF_HANDS*2);

  SetStatBonus(P_CON,  10);
  SetStatBonus(P_DEX, -10);
  SetStatBonus(P_INT, -13);
  SetStatBonus(P_STR,  13);
  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(2 * MAX_SUNBRIGHT);
  SetLong(
 "@@Nombre@@ es @@ind@@ gigante. Su forma es como la de un humano, pero ¡es\n"
 "casi el doble de grande!. @@Nombre@@ debe ser lent@@suf@@, pero muy\n"
 "fuerte.\n");
  SetRaceDescription(
"Fisicamente los gigantes son parecidos a los humanos, pero aproximadamente son\n\
el doble de grandes. Carecen casi completamente de pelo excepto por una gran\n\
cabellera que suelen llevar recogida en una coleta o una poblada barba de color\n\
oscuro. Son muy fuertes pero no demasiado agiles.\n\
Como luchadores son fieros y resistentes, y no temen enfrentarse a criatura\n\
alguna. Su temperamento es muy fuerte y desprecian a las otras razas del\n\
mundo, lo que ha producido que esten enfrentados con casi todas ellas.\n\
Solamente se alian con trolls y orcos cuando tienen algun causa comun.\n\
Son negados para la magia, aunque pueden utilizar objetos magicos hechos por\n\
otras razas. Viven en un tipo de monarquia militar y su objetivo ultimo es\n\
intentar conquistar el resto del mundo.\n");
}
