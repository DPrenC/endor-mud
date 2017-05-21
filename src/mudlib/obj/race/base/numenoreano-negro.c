/*
DESCRIPCION  : d�nedain malos.
Fichero: /obj/race/base/numenoreano-negro.c
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

  SetAlign  (-30);
  SetMaxFood   (100);
  SetMaxDrink  (90);
  SetMaxAlcohol    (105);
  SetSize(P_SIZE_LARGE);

  SetWeight (105000);
  SetBando(P_BANDO_OSCURIDAD);
  
  AddHand   ("fuerte mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand   ("fuerte mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus   (P_CON, 2);
  SetStatBonus   (P_DEX, 0);
  SetStatBonus   (P_INT, 1);
  SetStatBonus   (P_STR, 1);
    SetStatBonus   ("Cha", 1);
      SetStatBonus   (P_WIS, 0);
  SetResistance(DT_FIRE,8);
SetResistance(DT_COLD,5);
SetResistance(DT_POISON,5);
SetResistance(DT_PSYCHO,3);
                  SetResistance(DT_ACID,  1);
  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(3 * MAX_SUNBRIGHT);
  SetLong(
  "@@Nombre@@ es @@ind@@ N�men�rean@@suf@@ Negr@@suf@@, descendiente de los Altos Hombres "
  "de Oesternesse.\n"
  "@@Nombre@@ es muy alt@@suf@@, dotad@@suf@@ de un f�sico poderoso y con la apariencia "
  "de un gran vigor y fortaleza.\n"
  "Su piel es muy atezada por influencia del clima c�lido al que su gente se ha visto "
  "expuesta durante milenios, pero su cabello negro azabache, as� como sus hermosas "
  "facciones y el aire de majestad que desprenden, hacen innegable su ascendencia "
  "n�men�reana.\n"
  "En su rostro se mezclan el orgullo, la altaner�a y la impiedad, acentuado todo ello "
  "por el fr�o gris acerado de sus ojos, que lo miran a todo y a todos como si "
  "cuestionaran su derecho a existir.\n");
  SetRaceDescription(
  "Los N�men�reanos Negros descienden de los colonos y marineros de los �ltimos d�as de "
  "N�menor, cuando sus habitantes se volvieron malvados y orgullosos.\n"
  "La mayor�a de sus huestes partieron a la conquista de Aman junto con el �ltimo rey, "
  "Ar-Pharaz�n, y perecieron, pero los pocos que aguardaron en las colonias y puertos "
  "siguieron manteniendo su cultura, y no tardaron en convertirse en lugartenientes y "
  "tiranos de los hombres menores, bajo la �gira de Sauron, y a partir de entonces no "
  "dudaron en guerrear contra Gondor y los D�nedain supervivientes.\n"
  "A finales de la Tercera Edad, viven en pugna continua por el poder con los Corsarios "
  "de Umbar y los Haradrim, aunque en momentos de necesidad y en contra de sus enemigos "
  "D�nedain y Elfos, siempre acaban ali�ndose.\n"
  "Los N�men�reanos Negros se consideran superiores al resto de hombres, son "
  "orgullosos, crueles, y despiadados, aunque son soberbios guerreros y marineros, "
  "habi�ndo abrazado muchos la magia negra de Sauron para convertirse en temidos "
  "nigromantes.\n");
}