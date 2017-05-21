/*
DESCRIPCION  : un enano del clan Pu�of�rreo, originarios del norte de las Orocarni.
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
  SetAlign(10);
  SetMaxFood(115);
  SetMaxDrink(90);
  SetMaxAlcohol(205);
  SetWeight(77000);
  SetSize(P_SIZE_MEDIUM);
  SetBando(P_BANDO_NEUTRO);
  AddHand("callosa mano derecha", 0, WEAPON_CLASS_OF_HANDS*2);
  AddHand("callosa mano izquierda", 0, WEAPON_CLASS_OF_HANDS*2);

  SetStatBonus(P_CON,3);
  SetStatBonus(P_DEX,-3);
  SetStatBonus(P_INT,0);
  SetStatBonus(P_STR,3);
  SetStatBonus(P_WIS, -1);
SetStatBonus("Cha", -1);
  SetResistance(DT_FIRE,20);
SetResistance(DT_COLD,10);
SetResistance(DT_GAS,7);
SetResistance(DT_POISON,5);
SetResistance(DT_PSYCHO,40);
SetResistance(DT_NOAIR,10);
SetResistance(DT_WATER,-45);
SetResistance(MT_WATER,-35);
                  SetResistance(DT_ACID,  5);
  SetIVision(-REL_STATE(ND_PRENOON, MAX_SUNBRIGHT));
  SetUVision(MAX_SUNBRIGHT);

  SetLong(
"@@Nombre@@ es @@ind@@ enan@@suf@@ del clan Pu�of�rreo.\n"
"Con la t�pica constituci�n de los enanos, @@Nombre@@ es m�s corpulent@@suf@@ y ligeramente "
"m�s alt@@suf@@ de lo com�n en su raza.\n"
"Sus hombros fornidos y gruesos brazos poseen unos m�sculos formidables.\n"
"@@Nombre@@ tiene unos rasgos amplios que transmiten gran firmeza y determinaci�n, "
"enmarcados por abundante y desgre�ado cabello cobrizo, y sus acerados ojos grises "
"denotan un inquebrantable estoicismo y gran disciplina interior.\n");
SetRaceDescription(
"El gran clan de los Pu�of�rreo ha establecido su hogar al norte de las Orocarni, "
"cerca de las tierras de los Barbatiesa.\n"
"Gente dura, laboriosa y aguerrida, los Pu�of�rreo son famosos por la gran calidad de "
"sus objetos y armas de hierro, en cuya extracci�n y forja se han especializado desde "
"anta�o, aprovech�ndo los enormes yacimientos que se hayan bajo sus enclaves.\n"
"Grandes guerreros, sus huestes no muy numerosas pero bien guarnecidas con pesadas "
"armaduras y poderosas armas han combatido en innumerables batallas tanto al Este como "
"al Oeste, contra todos los que intentaron penetrar en sus tierras, pero tambi�n "
"socorriendo a otros clanes enanos o incluso contratados como mercenarios de �lite.\n"
"Sus enclaves, bien protegidos y defendidos han derrotado a huestes enemigas muy "
"superiores en n�mero, por la inquebrantable tenacidad de sus guerreros y la gran "
"disciplina de sus regimientos.\n");
}