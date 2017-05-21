/*
DESCRIPCION  : Elfos Silvanos o de los bosques o Nandor, los más débiles de todos pero los más apegados a la Tierra Media
de todos. Son los más esquivos y rústicos.
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
"No tan alt@@suf@@ como el resto de razas élficas, @@Nombre@@ es delgad@@suf@@ y de "
"constitución muy ágil y ligera.\n"
"Sus movimientos son livianos y fluidos incluso para tratarse de @@ind@@ elf@@suf@@, y "
"su estilizada figura tiene toda la elegancia y la nobleza que caracterizan a los elfos.\n"
"Su rostro, de piel clara,perfecta y rasgos de una hermosura sobrehumana, expresa la "
"alegría de un pueblo que ama la tierra en la que vive por encima de todo y no añora "
"ninguna otra cosa.\n"
"La luz de las estrellas parece danzar sobre sus dorados cabellos y en sus claros ojos "
"azules, la sabiduría de los elfos se mezcla con la cautela y la prevención.\n"
"@@Nombre@@ transmite en conjunto una sensación de alegre despreocupación, aunque bajo "
"ella puede esconderse una seria determinación y cautela.\n");
  SetRaceDescription(

"Los Elfos Silvanos son un conjunto de antiguos pueblos élficos que habitan desde edades "
"atrás en los tupidos bosques y lugares agrestes de la Tierra Media.\n"
"Nunca llegaron a las orillas del Gran Mar como sus primos los Elfos Grises ni a "
"Valinor, y por ello son un pueblo más rústico y menos desarrollado.\n"
"Aunque inmortales,  son escasamente organizados, llevando una vida errante por sus "
"tierras a las que protegen con gran celo.\n"
"No existe un pueblo en toda la Tierra Media mejor dotado para la música, que "
"entienda tan bien a la naturaleza ni que tenga un oído más fino, una vista más "
"penetrante o un paso más sigiloso, pues hasta para el resto de elfos resulta "
"difícil localizar a un Elfo Silvano si este no lo desea.\n"
"Sus ropas, herramientas, armas y viviendas son de materiales y hechura sencilla, "
"aunque hermosamente confeccionados y tallados.\n"
"Son los mejores arqueros, rastreadores, músicos y cazadores de todos los pueblos "
"élficos, aunque son desconfiados con los desconocidos que entran en sus tierras.\n");
}
