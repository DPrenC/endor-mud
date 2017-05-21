/*
DESCRIPCION  : Elfos Silvanos o de los bosques o Nandor, los m�s d�biles de todos pero los m�s apegados a la Tierra Media
de todos. Son los m�s esquivos y r�sticos.
FICHERO      : /obj/race/base/silvano.c

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
  SetMaxFood(70);
  SetBando(P_BANDO_LUZ);

  SetMaxDrink(100);
  SetMaxAlcohol(80);
  SetWeight(70000);
  SetSize(P_SIZE_LARGE);

  AddHand("elegante mano derecha", 0, WEAPON_CLASS_OF_HANDS);
  AddHand("elegante mano izquierda", 0, WEAPON_CLASS_OF_HANDS);

  SetStatBonus (P_CON,-1);
  SetStatBonus (P_DEX,4);
  SetStatBonus (P_INT,1);
  SetStatBonus (P_STR,-1);
  SetStatBonus(P_WIS, 0);
SetStatBonus("Cha", 0);
  SetResistance(DT_COLD,10);
SetResistance(DT_GAS,-25);
SetResistance(DT_POISON,10);
SetResistance(DT_NOAIR,-25);
                  SetResistance(DT_ACID,  -15);
  SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
  SetUVision(2 * MAX_SUNBRIGHT);
  SetLong(
"@@Nombre@@ es @@ind@@ Elf@@suf@@ Silvan@@suf@@.\n"
"No tan alt@@suf@@ como el resto de razas �lficas, @@Nombre@@ es delgad@@suf@@ y de "
"constituci�n muy �gil y ligera.\n"
"Sus movimientos son livianos y fluidos incluso para tratarse de @@ind@@ elf@@suf@@, y "
"su estilizada figura tiene toda la elegancia y la nobleza que caracterizan a los elfos.\n"
"Su rostro, de piel clara,perfecta y rasgos de una hermosura sobrehumana, expresa la "
"alegr�a de un pueblo que ama la tierra en la que vive por encima de todo y no a�ora "
"ninguna otra cosa.\n"
"La luz de las estrellas parece danzar sobre sus dorados cabellos y en sus claros ojos "
"azules, la sabidur�a de los elfos se mezcla con la cautela y la prevenci�n.\n"
"@@Nombre@@ transmite en conjunto una sensaci�n de alegre despreocupaci�n, aunque bajo "
"ella puede esconderse una seria determinaci�n y cautela.\n");
  SetRaceDescription(

"Los Elfos Silvanos son un conjunto de antiguos pueblos �lficos que habitan desde edades "
"atr�s en los tupidos bosques y lugares agrestes de la Tierra Media.\n"
"Nunca llegaron a las orillas del Gran Mar como sus primos los Elfos Grises ni a "
"Valinor, y por ello son un pueblo m�s r�stico y menos desarrollado.\n"
"Aunque inmortales,  son escasamente organizados, llevando una vida errante por sus "
"tierras a las que protegen con gran celo.\n"
"No existe un pueblo en toda la Tierra Media mejor dotado para la m�sica, que "
"entienda tan bien a la naturaleza ni que tenga un o�do m�s fino, una vista m�s "
"penetrante o un paso m�s sigiloso, pues hasta para el resto de elfos resulta "
"dif�cil localizar a un Elfo Silvano si este no lo desea.\n"
"Sus ropas, herramientas, armas y viviendas son de materiales y hechura sencilla, "
"aunque hermosamente confeccionados y tallados.\n"
"Son los mejores arqueros, rastreadores, m�sicos y cazadores de todos los pueblos "
"�lficos, aunque son desconfiados con los desconocidos que entran en sus tierras.\n");
}
