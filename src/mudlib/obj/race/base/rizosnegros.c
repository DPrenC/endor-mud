/*
DESCRIPCION  : un enano del clan de los Morenos o Rizosnegros , del sur de las 
monta�as Orocarni.
FICHERO      : /obj/race/base/rizosnegros.c
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
  SetAlign(-5);
  SetMaxFood(115);
  SetMaxDrink(80);
  SetMaxAlcohol(200);
  SetWeight(74000);
  SetSize(P_SIZE_MEDIUM);
  SetBando(P_BANDO_NEUTRO);
  AddHand("callosa mano derecha", 0, WEAPON_CLASS_OF_HANDS*2);
  AddHand("callosa mano izquierda", 0, WEAPON_CLASS_OF_HANDS*2);

  SetStatBonus(P_CON,3);
  SetStatBonus(P_DEX,-3);
  SetStatBonus(P_INT,-1);
  SetStatBonus(P_STR,2);
  SetStatBonus(P_WIS, -1);
SetStatBonus("Cha", -1);
  SetResistance(DT_FIRE,25);
SetResistance(DT_COLD,5);
SetResistance(DT_GAS,10);
SetResistance(DT_POISON,5);
SetResistance(DT_PSYCHO,40);
SetResistance(DT_NOAIR,10);
SetResistance(DT_WATER,-40);
SetResistance(MT_WATER,-30);
                  SetResistance(DT_ACID,  7);
  SetIVision(-REL_STATE(ND_PRENOON, MAX_SUNBRIGHT));
  SetUVision(MAX_SUNBRIGHT);

  SetLong(
"@@Nombre@@ es @@ind@@ enan@@suf@@ del clan de los Morenos o Rizosnegros.\n"
"Robust@@suf@@, fornid@@suf@@, achaparrad@@suf@@ y de grandes manos y pies como todos "
"los de su raza, @@Nombre@@ se caracteriza por su piel muy oscura, y su larga cabellera "
"azabache, irsuta y muy rizada.\n"
"Las anchas facciones de su rostro muestran un car�cter disciplinado, posesivo y hosco.\n"
"Bajo el amplio y poblado entrecejo rizado, sus ojos oscuros brillan como ascuas de "
"carb�n, con una ferocidad, codicia y furia contenidos que no convendr�a despertar.\n");
SetRaceDescription(
"El clan de los Morenos o Rizosnegros fue fundado por uno de los Grandes Padres de la "
"raza enana que despert� en las Orocarni.\n"
"Este clan levant� un poderoso reino en una zona muy rica en minerales, pero con gran "
"inestabilidad geol�gica, siendo abundantes en ella las erupciones volc�nicas y dem�s "
"fen�menos violentos que han moldeado el car�cter de este pueblo enano.\n"
"Posesivos, celosos, avariciosos, desconfiados y prontos en la c�lera a�n para los "
"baremos de su raza, los Rizosnegros son adem�s altivos, despreciando a hombres, orcos "
"y elfos por igual, aunque como el resto de los enanos mantienen una relaci�n "
"inquebrantable con los dem�s clanes.\n"
"Grandes mineros y forjadores, no son buenos orfebres, pues los metales preciosos no "
"son muy abundantes en sus tierras y ello hace que sufran una ardiente pasi�n por "
"amasar riquezas que supera a la de cualquier otro enano.\n"
"Constructores capaces, no tienen un gran sentido de la belleza de sus primos, y sus "
"construcciones son siempre oscuras, monumentales y s�lidas aunque l�bregas, siendo "
"sus bastiones inespugnables y tenebrosos.\n"
"Debido a vivir en una tierra sacudida por terremotos, corrientes de lava y  nubes de "
"ceniza, han desarrollado una fuerte resistencia a todo ello, o quiz�s Aul� los creara "
"as�, pues preve�a lo que el destino les reservaba.\n"
"Son grandes y feroces guerreros que hanluchado contra todo tipo de criaturas e incluso "
"han accedido a los sobornos de Sauron para luchar de su parte en diversas guerras.\n"
"De tez, pelo y ojos oscuros, lucen cabelleras y magn�ficas barbas fuertemente rizadas, "
"lo que ha dado nombre a su clan.\n");
}