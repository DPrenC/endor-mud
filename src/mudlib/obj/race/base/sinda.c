/*
DESCRIPCION  : Elfos Sindar o Elfos Grises, los elfos m�s estables, elfos medios por as� decir.
FICHERO      : /obj/race/base/sinda.c
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
  SetAlign(50);
  SetBando(P_BANDO_LUZ);

  SetMaxFood(80);
  SetMaxDrink(100);
  SetMaxAlcohol(80);
  SetWeight(80000);
  SetSize(P_SIZE_LARGE);

  AddHand("estilizada mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("estilizada mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus (P_CON,0);
  SetStatBonus (P_DEX,3);
  SetStatBonus (P_INT,2);
  SetStatBonus (P_STR,0);
  SetStatBonus(P_WIS, 0);
SetStatBonus("Cha", 0);
  SetResistance(DT_COLD,15);
SetResistance(DT_GAS,-20);
SetResistance(DT_POISON,10);
SetResistance(DT_PSYCHO,5);
SetResistance(DT_NOAIR,-20);
                  SetResistance(DT_ACID,  -10);
  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(2 * MAX_SUNBRIGHT);
  SetLong(
"@@Nombre@@ es @@ind@@ Elf@@suf@@ Sinda.\n"
"Casi tan alt@@suf@@ como  un elfo Noldo, pero de constituci�n a�n m�s estilizada y "
"elegante que este pueblo, @@Nombre@@ es de constituci�n m�s poderosa que un elfo "
"silvano.\n"
"Su piel es clara y exenta de toda m�cula, como jam�s podr�a serlo la de un hombre mortal,"
" y el noble rostro de �lficas facciones est� enmarcado por cabello largo, liso y rubio, "
"transmitiendo una sensaci�n de gentil se�or�o.\n"
"Sus ojos, de un profundo azul claro, est�n colmados por la sabidur�a y la experiencia que "
"dan los siglos y destilan una mirada tranquila y apacible.\n"
"Sus movimientos pausados emanan gran tranquilidad y paz, y en conjunto "
"@@Nombre@@ posee la maravilla con la que solo puede contar un individuo de la raza "
"�lfica.\n");
  SetRaceDescription(
"Los Sindar o Elfos Grises nunca cruzaron el Gran Mar hacia Valinor pero en la "
"Primera Edad bajo el Rey Thingol y la reina maia Melian alcanzaron gran nobleza, "
"poder y sabidur�a.\n"
"Pese a haber sido diezmados y sus reinos destru�dos al igual que los de los Noldor, "
"est�n m�s apegados a la TierraMedia que �stos y son m�s numerosos.\n"
"Tras la p�rdida de sus ancestrales tierras, muchos emigraron al Este y se mezclaron "
"con sus parientes, los Elfos Silvanos, organiz�ndolos y creando reinos propios en los "
"espesos bosques orientales.\n"
"Aunque como todos los elfos son inmortales, son menos se�oriales y h�biles que los "
"Altos Elfos de Occidente, los Sindar son muy h�biles en la m�sica, la poes�a y por "
"encima de todo en la construcci�n de embarcaciones y la navegaci�n, pues jam�s han "
"existido mejores marinos.\n"
"No obstante, tambi�n son buenos guerreros y al no ser tan orgullosos como los Noldor "
"se relacionan mejor con otros pueblos.\n");
}
