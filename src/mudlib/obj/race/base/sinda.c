/*
DESCRIPCION  : Elfos Sindar o Elfos Grises, los elfos más estables, elfos medios por así decir.
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
"Casi tan alt@@suf@@ como  un elfo Noldo, pero de constitución aún más estilizada y "
"elegante que este pueblo, @@Nombre@@ es de constitución más poderosa que un elfo "
"silvano.\n"
"Su piel es clara y exenta de toda mácula, como jamás podría serlo la de un hombre mortal,"
" y el noble rostro de élficas facciones está enmarcado por cabello largo, liso y rubio, "
"transmitiendo una sensación de gentil señorío.\n"
"Sus ojos, de un profundo azul claro, están colmados por la sabiduría y la experiencia que "
"dan los siglos y destilan una mirada tranquila y apacible.\n"
"Sus movimientos pausados emanan gran tranquilidad y paz, y en conjunto "
"@@Nombre@@ posee la maravilla con la que solo puede contar un individuo de la raza "
"élfica.\n");
  SetRaceDescription(
"Los Sindar o Elfos Grises nunca cruzaron el Gran Mar hacia Valinor pero en la "
"Primera Edad bajo el Rey Thingol y la reina maia Melian alcanzaron gran nobleza, "
"poder y sabiduría.\n"
"Pese a haber sido diezmados y sus reinos destruídos al igual que los de los Noldor, "
"están más apegados a la TierraMedia que éstos y son más numerosos.\n"
"Tras la pérdida de sus ancestrales tierras, muchos emigraron al Este y se mezclaron "
"con sus parientes, los Elfos Silvanos, organizándolos y creando reinos propios en los "
"espesos bosques orientales.\n"
"Aunque como todos los elfos son inmortales, son menos señoriales y hábiles que los "
"Altos Elfos de Occidente, los Sindar son muy hábiles en la música, la poesía y por "
"encima de todo en la construcción de embarcaciones y la navegación, pues jamás han "
"existido mejores marinos.\n"
"No obstante, también son buenos guerreros y al no ser tan orgullosos como los Noldor "
"se relacionan mejor con otros pueblos.\n");
}
