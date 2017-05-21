/*
DESCRIPCION  : Los trasgos son orcos de las monta�as, dejados de la mano de Sauron 
y llevando una vida troglodita y primitiva en cavernas y t�neles. Son la raza m�s peque�a y degenerada de orcos.
FICHERO      : /obj/race/base/trasgo.c
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

  SetAlign  (-50);
  SetBando(P_BANDO_OSCURIDAD);
  
  SetMaxFood   (115);
  SetMaxDrink  (85);
  SetMaxAlcohol    (110);
  SetWeight (50000);
  SetSize(P_SIZE_SMALL);

  AddHand("furtiva garra derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("furtiva garra izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus(P_CON,  1); 
  SetStatBonus(P_DEX, 2); 
  SetStatBonus(P_INT,  -2); 
  SetStatBonus(P_STR,  1);
  
  SetStatBonus("Cha",  -2);
    SetStatBonus(P_WIS,  -4);
  SetResistance(DT_FIRE,10);
SetResistance(DT_COLD,5);
SetResistance(DT_GAS,15);
SetResistance(DT_NOAIR,15);
SetResistance(DT_WATER,-40);
                  SetResistance(DT_ACID,  1);
  SetIVision(-(MAX_SUNBRIGHT / 2));
  SetUVision(MAX_SUNBRIGHT);
  SetLong(
"@@Nombre@@ es un Trasgo, la raza de Orcos cavern�colas de las monta�as.\n"
"Ronda el metro veinte de altura y pesa unos 33 kilos.\n"
"@@Nombre@@ es una criatura enclenque y miserable, de cuerpo esmirriado pero fuerte, "
"r�pido y muy �gil.\n"
"Bajo su mugrienta piel oscura cubierta de un ralo pelaje gris, la fina musculatura se "
"adhiere a su esquel�tica osamenta.\n"
"Su encorvado cuerpo, se apoya sobre piernas cortas y muy arqueadas, de pies grandes y "
"cuadrados. Posee unos brazos nervudos cuyas largas manos dotadas de afiladas garras "
"casi llegan al suelo, permiti�ndole andar a cuatro patas si as� lo desea.\n"
"@@Nombre@@ tiene una faz alargada, con facciones angulosas, protuberantes cejas, nariz "
"prominente y mand�bula inferior triangular y muy desarrollada, cuajada de aguzados "
"colmillos. Sus ojillos rojos acostumbrados a la oscuridad arden con la chispa de la "
"malicia, la traici�n y el odio.\n");
 SetRaceDescription (
  "Los Trasgos son una subraza de Orcos que habitan las cuevas y profundos t�neles de "
  "las monta�as, especialmente las Nubladas y las Grises.\n"
  "Son criaturas cavern�colas, que odian y temen la luz del sol ante la que se sienten "
  "d�biles y enfermos.\n"
  "Los Trasgos son mal�volos y esmirriados, de largos brazos, espaldas encorvadas, "
  "patizambos, de largos colmillos y ojos peque�os y rojizos.\n"
  "Habitan en ciudades, tribus y comunidades en las profundidades de las monta�as, tanto "
  "en cavernas naturales como en las ruinas de antiguas mansiones enanas y su n�mero es "
  "ingente.\n"
  "Dirigidos por sus chamanes y caudillos, de vez en cuando bajan de las Monta�as y "
  "atacan a los Pueblos Libres y viven en permanente estado de guerra con los Enanos, "
  "con quienes comparten territorio, muy a pesar de ambas razas.\n"
  "Son cobardes, crueles, traicioneros y taimados por naturaleza y tan solo atacan si "
  "superan en n�mero al enemigo o lo pillan por sorpresa.\n"
  "Pese a todo, aman la violencia, la tortura y el combate y todos ellos son guerreros "
  "m�s o menos competentes.\n"
  "Su potente olfato los hace buenos rastreadores, y sus chamanes son capaces de "
  "desencadenar maleficios y poderes oscuros.\n");
//AddEquipment("gafas ahumadas", "/obj/sunglasses", 0, 0, ({ "gafas" }));
}
