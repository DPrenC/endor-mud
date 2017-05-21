/*Hobbit fuerte, el m�s robusto*/

#include <combat.h>
#include <config.h>
#include <attributes.h>
#include <nightday.h>
#include <properties.h>
#include <bandos.h>

inherit "/obj/raceobj";

create_blueprint(){
::create_blueprint();

SetAlign(30);
SetBando(P_BANDO_LUZ);

SetMaxFood(80);
SetMaxDrink(75);
SetMaxAlcohol(55);
SetSize(P_SIZE_SMALL);
SetWeight(23000);
AddHand("peque�a mano derecha", 0, WEAPON_CLASS_OF_HANDS);
AddHand("peque�a mano izquierda", 0, WEAPON_CLASS_OF_HANDS);
SetStatBonus(P_CON, 1);
SetStatBonus(P_INT, 0);
SetStatBonus(P_DEX, 3);
SetStatBonus(P_STR,     -3);
SetStatBonus(P_WIS, -3);
SetStatBonus("Cha", -4);
SetResistance(DT_POISON,5);
SetResistance(DT_PSYCHO,15);
SetResistance(MT_POISON,5);
SetResistance(MT_PSYCHO,15);

SetIVision(REL_STATE(ND_DAWN, MAX_SUNBRIGHT));
SetUVision(2 * MAX_SUNBRIGHT);
    SetLong("@@Nombre@@ es @@ind@@ hobbit Fuerte, la variante m�s robusta de Hobbit.\n"
    "Mide algo m�s de un metro, posee una constituci�n rechoncha y sus mofletudas "
    "facciones est�n enmarcadas por abundante cabello casta�o rizado.\n"
    "Sus ojos casta�os tienen una mirada amistosa pero ligeramente desconfiada, y sus "
    "ademanes son algo m�s bruscos y rudos de lo normal en los Hobbits.\n"
    "El detalle m�s rese�able de su persona son sus manos y pies, grandes y algo "
    "desproporcionados incluso para lo com�n entre los Medianos.\n");

SetRaceDescription(
"Los Fuertes son el grupo de hobbits m�s rechonchos y macizos.\n"
"Son algo m�s altos que los Pelosos pero no tanto como los Albos, y poseen grandes "
"manos y pies, llegando a utilizar en ocasiones botas y dem�s calzado que sus otros "
"parientes rechazan.\n"
"Rehuyen el contacto con otras razas y sus sitios preferidos para vivir son las "
"tierras bajas y las riberas de los r�os.\n"
"Son los �nicos hobbits que disfrutan con el manejo de peque�as embarcaciones e incluso "
"algunos saben nadar.\n");
}