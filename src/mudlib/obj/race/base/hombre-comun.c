/*
DESCRIPCION  : un humano b�sico
FICHERO      : /obj/race/base/humano-comun.c
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
  SetMaxFood   (100);
  SetMaxDrink  (100);
  SetMaxAlcohol    (100);
  SetSize(P_SIZE_LARGE);
  SetBando(P_BANDO_NEUTRO);
  SetWeight (75000);
  AddHand   ("mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand   ("mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus   (P_CON, 0);
  SetStatBonus   (P_DEX, 0);
  SetStatBonus   (P_INT, 0);
  SetStatBonus   (P_STR, 0);
        SetStatBonus ("Cha", 0);
      SetStatBonus (P_WIS, 0);

  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(3 * MAX_SUNBRIGHT);
  SetLong(
"@@Nombre@@ es @@ind@@ human@@suf@@ com�n de la Tierra Media.\n"
"De estatura y complexi�n medias, no podr�a asegurarse a qu� pueblo o tribu pertenece "
"pues nada en su aspecto llama la atenci�n.\n"
"@@Nombre@@ tiene cabello casta�o liso y sus ojos marrones poseen una mirada neutral e "
"indiferente.\n");

SetRaceDescription(
"La raza de los Hombres se ha extendido desde su aparici�n a lo largo y ancho de la "
"Tierra Media, dando lugar a toda clase de culturas y civlizaciones, muchas de las "
"cuales tienen marcado caracter distintivo y habiendo desarrollado sus "
"individuos rasgos caracter�sticos.\n"
"Empero, muchas de las gentes humanas de Endor podr�an confundirse entre cualquier "
"cultura y si destacan por algo en concreto, es por el hecho de no destacar en nada.\n"
"Los hombres de Bree, del Valle o del lago podr�an ser algunos ejemplos, a parte de toda "
"clase de vagabundos que hierran por los amplios territorios inexplorados de la "
"Tierra Media.\n");
}