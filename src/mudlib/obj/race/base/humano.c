/*
DESCRIPCION  : un humano
FICHERO      : /obj/race/base/humano.c
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
  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(3 * MAX_SUNBRIGHT);
  SetLong(
"@@Pl_Name@@ es un@@suf2@@ human@@suf@@. Tiene pelo oscuro y ojos marrones.\n\
Parece un individuo avispado.\n");


  SetRaceDescription(
  "La raza de los Hombres abarca un sin n�mero de subespecies, culturas y tribus distintas.\n"
  "Desde los esquivos Lossoth del fr�o norte a los crueles haradrim del �rido sur, "
  "pas�ndo por los n�madas Orientales o los Jinetes de Rohan, su principal "
  "caracter�stica, como la de los altos Hombres es el Don de la Muerte.\n"
  "Sin embargo, y al contrario que estos, tienen una vida relativamente corta, siendo "
  "raros los casos en que pasan del siglo de vida o llegan hasta esta edad con plenas "
  "facultades, son menos fuertes, refinados y poderosos, pero son innumerables y a "
  "finales de la Tercera Edad, los hombres comunes dominan casi la totalidad de la "
  "Tierra Media.\n"
  "Actualmente, muchos de estos pueblos han ca�do bajo el influjo maligno de Sauron, "
  "aunque algunos otros se mantienen neutrales o se le oponen abiertamente.\n");
  
}